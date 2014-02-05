"""Custom OTA commands for Samsung d2 devices """

def FullOTA_InstallEnd(info):
	info.script.AppendExtra('ifelse(is_substring("I797", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox mv /system/lib_att/libril-qc-qmi-1.so /system/lib/libril-qc-qmi-1.so"));')
	info.script.AppendExtra('ifelse(is_substring("I797", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox mv /system/lib_att/libril.so /system/lib/libril.so"));')
	info.script.AppendExtra('ifelse(is_substring("T999", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox mv /system/lib_tmo/libril-qc-qmi-1.so /system/lib/libril-qc-qmi-1.so"));')
        info.script.AppendExtra('ifelse(is_substring("T999", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox mv /system/lib_tmo/libril.so /system/lib/libril.so"));')
	info.script.AppendExtra('ifelse(is_substring("R530U", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox mv /system/lib_usc/libril-qc-qmi-1.so /system/lib/libril-qc-qmi-1.so"));')
        info.script.AppendExtra('ifelse(is_substring("R530U", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox mv /system/lib_usc/libril.so /system/lib/libril.so"));')
	info.script.AppendExtra('ifelse(is_substring("I535", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox mv /system/lib_vzw/libril-qc-qmi-1.so /system/lib/libril-qc-qmi-1.so"));')
        info.script.AppendExtra('ifelse(is_substring("I535", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox mv /system/lib_vzw/libril.so /system/lib/libril.so"));')
