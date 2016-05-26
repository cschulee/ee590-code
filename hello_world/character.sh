#!/bin/bash
# https://www.maketecheasier.com/finding-raspberry-pi-system-information/
# OS Version
cat /proc/version
cat /proc/sys/kernel/ostype
cat /proc/sys/kernel/osrelease

# CPU Configuration
cat /proc/cpuinfo

# Memory Configuration
cat /proc/meminfo
cat /proc/partitions
free -o -h

# USB Devices
lsusb -t

# Temperature
vcgencmd measure_temp

# CPU Frequency
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq

for src in arm core h264 isp v3d uart pwm emmc pixel vec hdmi dpi ; do \
echo -e "$src:\t$(vcgencmd measure_clock $src)" ; \
done

# Voltages
for id in core sdram_c sdram_i sdram_p ; do \
echo -e "$id:\t$(vcgencmd measure_volts $id)" ; \
done

# Codecs
for codec in H264 MPG2 WVC1 MPG4 MJPG WMV9 ; do \
echo -e "$codec:\t$(vcgencmd codec_enabled $codec)" ; \
done

# Query current internet connection type and configuration
ifconfig
cat /proc/sys/kernel/hostname

# Test internet speed
speedtest-cli
