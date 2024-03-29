#pragma once

#include"Advanced Engine Architecture.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CTexture
    {
        friend class CVideo;
        
        private : std::string FPath;
        private : std::uint32_t FIdentifier;

        private : CTexture(const std::string& PPath);
        private : bool operator==(const std::string& PPath) const;

        public : std::uint32_t OIdentifier() const;
        public : ~CTexture();
    };
}