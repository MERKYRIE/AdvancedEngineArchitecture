#pragma once

#include"Advanced Engine Architecture.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CCharacter
    {
        friend class CFont;
        
        private : std::uint32_t FIdentifier;

        private : CCharacter(TTF_Font* PFont , char PCode);

        public : std::uint32_t OIdentifier() const;
        public : ~CCharacter();
    };
}