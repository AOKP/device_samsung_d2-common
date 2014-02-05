"""Custom OTA commands for Samsung d2 devices """

def FullOTA_InstallEnd(info):
	info.script.AppendExtra('ifelse(is_substring("I797", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/proprietary/att/* /system/"));')
	info.script.AppendExtra('ifelse(is_substring("T999", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/proprietary/tmo/* /system/"));')
	info.script.AppendExtra('ifelse(is_substring("R530U", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/proprietary/usc/* /system/"));')
	info.script.AppendExtra('ifelse(is_substring("I535", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/proprietary/vzw/* /system/"));')
	info.script.AppendExtra('delete_recursive("/system/proprietary");')
