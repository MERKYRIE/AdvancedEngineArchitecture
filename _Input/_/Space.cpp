#include"Space.hpp"

#include"Debug.hpp"
#include"Input.hpp"
#include"Space\\Cuboid.hpp"
#include"Space\\Rectangle.hpp"
#include"Space\\Sphere.hpp"
#include"Time.hpp"
#include"Video.hpp"
#include"Video\\Mesh.hpp"
#include"Video\\VertexArrayObject.hpp"

namespace NAdvancedEngineArchitecture
{
    void CSpace::BInitialize()
    {
        FSea.reset(new NSpace::CRectangle);
        FSeaScale = 100.0F;
        FSeaPositionXY = 50.0F;
        FSeaPositionZ = -0.5F;
        FSea->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Sea.png"));
        FSea->OMesh()->OScaleX(FSeaScale);
        FSea->OMesh()->OScaleY(FSeaScale);
        FSea->OMesh()->OPositionX(FSeaPositionXY);
        FSea->OMesh()->OPositionY(FSeaPositionXY);
        FSea->OMesh()->OPositionZ(FSeaPositionZ);
        FPlane.reset(new NSpace::CCuboid);
        FPlaneScale = 0.5F;
        FPlanePosition = 0.0F;
        FPlaneSpeed = 0.025F;
        FPlaneAmplitude = 7.5F;
        FPlaneScore = 0;
        FPlane->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Plane.png"));
        FPlane->OMesh()->OScaleX(FPlaneScale);
        FPlane->OMesh()->OScaleY(FPlaneScale);
        FPlane->OMesh()->OPositionX(FSeaPositionXY);
        FPlane->OMesh()->OPositionY(FSeaPositionXY);
        FPlane->OMesh()->OPositionZ(FSeaPositionZ +  + FPlane->OMesh()->OScaleZ() / 2.0F + 5.0F);
        FShipScale = 2.0F;
        FShipSpeed = 0.005F;
        FShipAmplitudeX = 9.5F;
        FShipAmplitudeY = 15.0F;
        FTorpedoScale = 0.25F;
        FTorpedoPosition = 0.0F;
    }
    void CSpace::BUpdate()
    {
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo.ORatio() , 1.0F , 1'000.0F)};
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        glm::mat4 LView{1.0F};
        LView = glm::rotate(LView , glm::radians(-90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LView = glm::rotate(LView , glm::radians(90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LView = glm::translate(LView , -glm::vec3{FSeaPositionXY , FSeaPositionXY , 10.0F});
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LView[0][0]);
        FSea->OMesh()->ORender();
        if(GInput.OIsKeyHeld(SDL_SCANCODE_A))
        {
            FPlanePosition -= GTime.ORelative() * FPlaneSpeed;
            if(FPlanePosition < -FPlaneAmplitude)
            {
                FPlanePosition = -FPlaneAmplitude;
            }
        }
        if(GInput.OIsKeyHeld(SDL_SCANCODE_D))
        {
            FPlanePosition += GTime.ORelative() * FPlaneSpeed;
            if(FPlanePosition > +FPlaneAmplitude)
            {
                FPlanePosition = +FPlaneAmplitude;
            }
        }
        FPlane->OMesh()->OPositionX(FSeaPositionXY + FPlanePosition);
        FPlane->OMesh()->ORender();
        while(FShips.size() < 3)
        {
            std::shared_ptr<NSpace::CCuboid> LShip{new NSpace::CCuboid};
            LShip->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Ship.png"));
            LShip->OMesh()->OScaleX(FShipScale);
            LShip->OMesh()->OScaleY(FShipScale);
            std::random_device LGenerator;
            std::uniform_real_distribution<float> LDistributor{-FShipAmplitudeX , +FShipAmplitudeX};
            do
            {
                LShip->OMesh()->OPositionX(FSeaPositionXY + LDistributor(LGenerator));
                LShip->OMesh()->OPositionY(FSeaPositionXY + FShipAmplitudeY);
                LShip->OMesh()->OPositionZ(FSeaPositionZ + LShip->OMesh()->OScaleZ() / 2.0F);
            }
            while(std::ranges::any_of(FShips , [&LShip](const std::shared_ptr<const NSpace::CCuboid>& PShip){return LShip->OCollides(*PShip);}));
            FShips.emplace_back(LShip);
        }
        std::ranges::for_each(FShips , [this](const std::shared_ptr<const NSpace::CCuboid>& PShip){PShip->OMesh()->OPositionY(PShip->OMesh()->OPositionY() - GTime.ORelative() * FShipSpeed);});
        for(std::vector<std::shared_ptr<NSpace::CCuboid>>::const_iterator LIterator{FShips.begin()} ; LIterator != FShips.end() ; LIterator++)
        {
            if((*LIterator)->OMesh()->OPositionY() < FSeaPositionXY - FShipAmplitudeY)
            {
                FShips.erase(LIterator);
                return;
            }
        }
        std::ranges::for_each(FShips , [](const std::shared_ptr<const NSpace::CCuboid>& PShip){PShip->OMesh()->ORender();});
        if(GInput.OIsKeyHeld(SDL_SCANCODE_SPACE))
        {
            if(!FTorpedo)
            {
                FTorpedo.reset(new NSpace::CSphere);
                FTorpedo->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Torpedo.png"));
                FTorpedo->OMesh()->OScaleX(FTorpedoScale);
                FTorpedo->OMesh()->OScaleY(FTorpedoScale);
                FTorpedo->OMesh()->OPositionX(FPlane->OMesh()->OPositionX());
                FTorpedo->OMesh()->OPositionY(FPlane->OMesh()->OPositionY());
                FTorpedo->OMesh()->OPositionZ(FPlane->OMesh()->OPositionZ());
                FTorpedoPosition = FPlane->OMesh()->OPositionZ();
            }
        }
        if(FTorpedo)
        {
            FTorpedoPosition -= GTime.ORelative() * 0.005F;
            FTorpedo->OMesh()->OPositionZ(FTorpedoPosition);
            if(FTorpedo->OMesh()->OPositionZ() < FSeaPositionZ)
            {
                FTorpedo.reset();
                return;
            }
            for(std::vector<std::shared_ptr<NSpace::CCuboid>>::const_iterator LIterator{FShips.begin()} ; LIterator != FShips.end() ; LIterator++)
            {
                if(FTorpedo->OCollides(**LIterator))
                {
                    FTorpedo.reset();
                    FShips.erase(LIterator);
                    FShipSpeed += 0.001F;
                    FPlaneScore++;
                    return;
                }
            }
            FTorpedo->OMesh()->ORender();
        }
    }
    void CSpace::BDeinitialize()
    {
        FTorpedo.reset();
        FShips.clear();
        FPlane.reset();
        FSea.reset();
    }
}