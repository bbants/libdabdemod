/*
 * From SDR-J
 */

#ifndef __DAB_UTIL__PHASE_REFERENCE
#define __DAB_UTIL__PHASE_REFERENCE

#include "util/fft.h"

#include <constants/transmission_modes.h>
#include <types/common_types.h>

#include <cstdint>
#include <vector>

namespace dab
  {

  namespace __internal_demod
    {

    /**
     * @internal
     * @author Felix Morgner
     *
     * @brief DAB phase reference
     *
     * This class provides a DAB phas reference
     * Most of this implementation is reproduced and adapted from Jan van Katwijk's
     * dab-rpi (https://github.com/JvanKatwijk/dab-rpi) which is released under GPLv2.
     */
    struct phase_reference
      {
      phase_reference(__internal_common::types::transmission_mode const & mode, std::int16_t signalLevel);

      std::int32_t index(__internal_common::sample_t * data, std::uint32_t const size);

      std::vector<__internal_common::sample_t> const & table();

      private:
        __internal_common::types::transmission_mode const m_mode;
        std::int16_t m_signalLevel;
        std::vector<__internal_common::sample_t> m_table;

        fft m_forward;
        fft m_backward;
      };

    }

  }

#endif

