#include"Mesh.hpp"

#include"Texture.hpp"
#include"VertexArrayObject.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    CMesh::CMesh()
    {
        FPositionX = 0.0F;
        FPositionY = 0.0F;
        FPositionZ = 0.0F;
        FScaleX = 1.0F;
        FScaleY = 1.0F;
        FScaleZ = 1.0F;
    }
    const std::shared_ptr<const CVertexArrayObject>& CMesh::OVertexArrayObject() const
    {
        return FVertexArrayObject;
    }
    const CMesh& CMesh::OVertexArrayObject(const std::shared_ptr<const CVertexArrayObject>& PVertexArrayObject)
    {
        FVertexArrayObject = PVertexArrayObject;
        return *this;
    }
    const std::shared_ptr<const CTexture>& CMesh::OTexture() const
    {
        return FTexture;
    }
    const CMesh& CMesh::OTexture(const std::shared_ptr<const CTexture>& PTexture)
    {
        FTexture = PTexture;
        return *this;
    }
    float CMesh::OPositionX() const
    {
        return FPositionX;
    }
    const CMesh& CMesh::OPositionX(float PValue)
    {
        FPositionX = PValue;
        return *this;
    }
    float CMesh::OPositionY() const
    {
        return FPositionY;
    }
    const CMesh& CMesh::OPositionY(float PValue)
    {
        FPositionY = PValue;
        return *this;
    }
    float CMesh::OPositionZ() const
    {
        return FPositionZ;
    }
    const CMesh& CMesh::OPositionZ(float PValue)
    {
        FPositionZ = PValue;
        return *this;
    }
    float CMesh::OScaleX() const
    {
        return FScaleX;
    }
    const CMesh& CMesh::OScaleX(float PValue)
    {
        FScaleX = PValue;
        return *this;
    }
    float CMesh::OScaleY() const
    {
        return FScaleY;
    }
    const CMesh& CMesh::OScaleY(float PValue)
    {
        FScaleY = PValue;
        return *this;
    }
    float CMesh::OScaleZ() const
    {
        return FScaleZ;
    }
    const CMesh& CMesh::OScaleZ(float PValue)
    {
        FScaleZ = PValue;
        return *this;
    }
    const CMesh& CMesh::ORender() const
    {
        glm::mat4 LModel{1.0F};
        LModel = glm::translate(LModel , glm::vec3{FPositionX - FScaleX / 2.0F , FPositionY - FScaleY / 2.0F , FPositionZ - FScaleZ / 2.0F});
        LModel = glm::scale(LModel , glm::vec3{FScaleX , FScaleY , FScaleZ});
        glUniformMatrix4fv(5 , 1 , GL_FALSE , &LModel[0][0]);
        glBindTexture(GL_TEXTURE_2D , FTexture->OIdentifier());
        FVertexArrayObject->ORender();
        return *this;
    }
    CMesh::~CMesh()
    {
        FTexture.reset();
        FVertexArrayObject.reset();
    }
}