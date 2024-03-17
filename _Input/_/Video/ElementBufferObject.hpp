#pragma once

#include"Advanced Engine Architecture.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CElementBufferObject
    {
        private : std::uint32_t FIdentifier;
        private : std::intmax_t FSize;

        public : CElementBufferObject(const std::vector<std::uint32_t>& PElements);
        public : std::intmax_t OSize() const;
        public : ~CElementBufferObject();
    };
}