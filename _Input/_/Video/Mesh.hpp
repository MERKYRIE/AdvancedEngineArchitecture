#pragma once

#include"Advanced Engine Architecture.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CTexture;
    class CVertexArrayObject;
    
    class CMesh
    {
        private : std::shared_ptr<const CVertexArrayObject> FVertexArrayObject;
        private : std::shared_ptr<const CTexture> FTexture;
        private : float FPositionX;
        private : float FPositionY;
        private : float FPositionZ;
        private : float FScaleX;
        private : float FScaleY;
        private : float FScaleZ;

        public : CMesh();
        public : const std::shared_ptr<const CVertexArrayObject>& OVertexArrayObject() const;
        public : const CMesh& OVertexArrayObject(const std::shared_ptr<const CVertexArrayObject>& PVertexArrayObject);
        public : const std::shared_ptr<const CTexture>& OTexture() const;
        public : const CMesh& OTexture(const std::shared_ptr<const CTexture>& PTexture);
        public : float OPositionX() const;
        public : const CMesh& OPositionX(float PValue);
        public : float OPositionY() const;
        public : const CMesh& OPositionY(float PValue);
        public : float OPositionZ() const;
        public : const CMesh& OPositionZ(float PValue);
        public : float OScaleX() const;
        public : const CMesh& OScaleX(float PValue);
        public : float OScaleY() const;
        public : const CMesh& OScaleY(float PValue);
        public : float OScaleZ() const;
        public : const CMesh& OScaleZ(float PValue);
        public : const CMesh& ORender() const;
        public : ~CMesh();
    };
}