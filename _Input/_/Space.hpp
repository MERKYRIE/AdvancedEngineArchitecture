#pragma once

#include"Advanced Engine Architecture.hpp"

namespace NAdvancedEngineArchitecture
{
    namespace NSpace
    {
        class CRectangle;
        class CCuboid;
        class CSphere;
    }
    
    inline class CSpace
    {
        friend std::int32_t (::main(std::int32_t , char**));

        private : std::shared_ptr<NSpace::CRectangle> FSea;
        private : float FSeaScale;
        private : float FSeaPositionXY;
        private : float FSeaPositionZ;
        private : std::shared_ptr<NSpace::CCuboid> FPlane;
        private : float FPlaneScale;
        private : float FPlanePosition;
        private : float FPlaneSpeed;
        private : float FPlaneAmplitude;
        private : std::intmax_t FPlaneScore;
        private : std::vector<std::shared_ptr<NSpace::CCuboid>> FShips;
        private : float FShipScale;
        private : float FShipSpeed;
        private : float FShipAmplitudeX;
        private : float FShipAmplitudeY;
        private : std::shared_ptr<NSpace::CSphere> FTorpedo;
        private : float FTorpedoScale;
        private : float FTorpedoPosition;

        private : void BInitialize();
        private : void BUpdate();
        private : void BDeinitialize();
    }
    GSpace;
}