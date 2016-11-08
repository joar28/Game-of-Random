/* Copyright
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include "StateInterface.h"  // NOLINT(build/include)

StateInterface::StateInterface() {
    next_state_data.next_state_ptr = this;
}

void StateInterface::InitData() {

}
