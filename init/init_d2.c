/*
Copyright (c) 2013, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the following
disclaimer in the documentation and/or other materials provided
with the distribution.
* Neither the name of The Linux Foundation nor the names of its
contributors may be used to endorse or promote products derived
from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);
    if (strstr(bootloader, "I747")) {
        // d2att
        property_set("ro.product.device", "d2att");
        property_set("ro.product.model", "SGH-I747");
        property_set("ro.build.description", "d2uc-user 4.1.2 JZO54K I747UCDMG2 release-keys");
        property_set("ro.build.fingerprint", "samsung/d2uc/d2att:4.1.2/JZO54K/I747UCDMG2:user/release-keys");
        property_set("telephony.lteOnGsmDevice","1");
        property_set("gsm.current.phone-type", "1");
    } else if (strstr(bootloader, "T999")) {
        // d2tmo
        property_set("ro.product.device", "d2tmo");
        property_set("ro.product.model", "SGH-T999");
        property_set("ro.build.description", "d2uc-user 4.1.2 JZO54K T999UVDMD5 release-keys");
        property_set("ro.build.fingerprint", "samsung/d2uc/d2att:4.1.2/JZO54K/T999UVDMD5:user/release-keys");
        property_set("telephony.lteOnGsmDevice","1");
        property_set("gsm.current.phone-type", "1");
    } else if (strstr(bootloader, "R530U")) {
        // d2usc
        property_set("ro.product.device", "d2usc");
        property_set("ro.product.model", "SCH-R530U");
        property_set("ro.build.description", "d2usc-user 4.1.1 JRO03L R530UVXALK5 release-keys");
        property_set("ro.build.fingerprint", "samsung/d2usc/d2usc:4.1.1/JRO03L/R530UVXALK5:user/release-keys");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_cdma_sub", "0");
        property_set("gsm.current.phone-type", "2");
    } else if (strstr(bootloader, "I535")) {
        // d2vzw
        property_set("ro.product.device", "d2vzw");
        property_set("ro.product.model", "SCH-I535");
        property_set("ro.build.description", "d2vzw-user 4.3 JSS15J I535VRUCML1 release-keys");
        property_set("ro.build.fingerprint", "Verizon/d2vzw/d2vzw:4.3/JSS15J/I535VRUCML1:user/release-keys");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.cdma.home.operator.numeric", "311480");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.subscribe_on_ruim_ready", "true");
        property_set("ro.telephony.default_network", "8");
        property_set("keyguard.no_require_sim", "true");
        property_set("DEVICE_PROVISIONED", "1");
        property_set("ro.config.svlte1x", "true");
        property_set("ro.config.qc_lte_network_modes", "true");
        property_set("persist.radio.no_wait_for_card", "0");
        property_set("persist.radio.snapshot_enabled", "1");
        property_set("persist.radio.snapshot_timer", "22");
        property_set("ro.config.multimode_cdma", "1");
        property_set("ro.config.combined_signal", "true");
        property_set("ro.gsm.data_retry_config=max_retries", "infinite,5000,5000,60000,120000,480000,900000");
        property_set("persist.eons.enabled", "false");
        property_set("ro.telephony.default_cdma_sub", "0");
        property_set("ro.config.vc_call_vol_steps", "7");
        property_set("gsm.current.phone-type", "2");
    }

    // rild args
    property_set("rild.libargs", "-d /dev/smd0");

    // Hardware info
    property_set("ro.device.chipset", "Qualcomm Snapdragon S4 MSM8960");
    property_set("ro.device.cpu", "1.5 GHz dual-core Krait");
    property_set("ro.device.gpu", "Qualcomm Adreno 225");
    property_set("ro.device.rear_cam", "8 MP");
    property_set("ro.device.front_cam", "1.9 MP");
    property_set("ro.device.screen_res", "720x1280");

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
