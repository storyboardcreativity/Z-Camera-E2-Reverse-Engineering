# Common info

## AES encryption

Z-CAM use AES (128-bit) CFB encryption for main firmware data ZIP-archive (**update_data.bin**).

| E2 firmware version | AES key (hex bytes) | AES initial vector (hex bytes) |
|:---:|:---:|:---:|
| 0.83 | X | X |
| 0.87 </br> 0.88 </br> 0.93 | ```53 7E 15 16``` </br> ```28 AE D2 A6``` </br> ```AB F7 15 88``` </br> ```09 CF 22 3C``` | ```00 01 02 03``` </br> ```04 05 06 07``` </br> ```08 09 0A 0B``` </br> ```0C 0D 0E 0F``` |
| 0.96 </br> 0.97 </br> 0.97.1 </br> 0.98 </br> 0.98.1 </br> 0.98.2 | ```CF 55 5B B7``` </br> ```BF 0E 45 6E``` </br> ```94 10 D0 15``` </br> ```D7 5F E3 5B``` | ```00 01 02 03``` </br> ```04 05 06 07``` </br> ```08 09 0A 0B``` </br> ```0C 0D 0E 0F``` |

#### Legend

`X` : encryption is not used

## Passwords for archives in firmware

Here are passwords that are user for each encrypted ZIP-archive (for example, **recovery.zip** or **update_data.zip**):

| Version | ZIP password |
|:---:|:---:|
|  0.83 </br> 0.87 </br> 0.93  | gmi!!emoclew |
|  0.94 </br> 0.95 </br> 0.96 </br> 0.97 </br> 0.97.1 </br> 0.98 </br> 0.98.1 </br> 0.98.2  | 1234564698742 |

## Hardware

| Model | SoC | Sensor |
|:---:|:---:|:---:|
| E2 | HiSilicon Hi3559A V100 | Sony IMX299 |
| E2C | HiSilicon Hi3559A V100 | Sony IMX159 |
| E2G | HiSilicon Hi3559A V100 | Sony IMX344 |
| E2-S6 | HiSilicon Hi3559A V100 | Sony IMX571 |
| E2-F6 | HiSilicon Hi3559A V100 | Sony IMX410 |
| E2-F8 | HiSilicon Hi3559A V100 | Sony IMX455 |

## Partitions

| Partition | Description
|:---:|:---:|
| mmcblk0p1 | Boot partition |
| mmcblk0p2 | Environment data partition |
| mmcblk0p3 | Recovery |
| mmcblk0p4 | nv (mounted as /tmp/nv) |
| mmcblk0p5 | Linux Kernel |
| mmcblk0p6 | RootFS |
| mmcblk0p7 | pref (mounted as /tmp/data) |
| mmcblk0p8 | data (mounted as /tmp/storage) |
| mmcblk0p9 | hibernate (???) |

## Camera bootup process

#### U-Boot

U-Boot is started from eMMC memory (partition 1).
At this moment splash screen is shown on E2 screen (Z-CAM logo).

If power and record buttons are pressed - recovery OS starts.

Otherwise - main Linux Kernel starts.

#### Recovery

This contains own Linux Kernel and LZO-compressed filesystem.

