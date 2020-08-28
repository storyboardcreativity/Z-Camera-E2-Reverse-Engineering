# Z-CAM E2 Firmware v0.83

## Firmware structure

```
update.zip
├── install_binary
├── md5.txt
├── os_info.txt
├── update.script
├── version.txt
└── update_data.zip
    ├── uImage
    ├── app_data.tar.gz
    ├── pref.tar.gz
    ├── pref_reco.sh
    └── rootfs.tar.gz
```

#### update.zip

Firmware file, standard ZIP archive.

#### install_binary

ARM64 ELF executable. Executed on device when firmware is going to be installed. Processes firmware installation.

#### md5.txt

Contains MD5 hashes for some firmware files.

Example:
```
bafa0014dd8c1a33f55a8903f0adf60f  version.txt
136b09f1f29459b3a4d7d045461f78cc  update_data.zip

```

#### os_info.txt

For now I don't have info about it.

Example:
```
52d2943

```

#### update.script

Firmware installation script. It is executed in `install_binary`'s shell.

Example:
```
update unzip_data update_data.zip
update dd /dev/mmcblk0p5 uImage
update format /dev/mmcblk0p6 ext4
update extract /dev/mmcblk0p6 rootfs.tar.gz
update format /dev/mmcblk0p7 ext4
update extract /dev/mmcblk0p7 pref.tar.gz
update extract /dev/mmcblk0p8 app_data.tar.gz

```

#### version.txt

Contains firmware version.

Example:
```
0_83_1901031016_119bd55_eclipse_n

```

Here is explaination:
- `0_83` is "0.83" (version)
- `1901031016` is a firmware build date
- `119bd55` is a current firmware version commit hash
- `eclipse` is a model codename ("eclipse" is E2's codename)
- `n` is "no" (means "no signature checking bypass").

#### update_data.zip

Firmware data, standard ZIP archive.

#### uImage

Linux kernel.

#### app_data.tar.gz

Not sure about this file. But in this firmware version it contains AI data for face recognition process.

#### pref.tar.gz

Contains some initial Z-CAM E2 settings (for example, Wi-Fi hotspot name and password).

#### pref_reco.sh

Bash script. For now I don't have info about it.

#### rootfs.tar.gz

Linux RootFS filesystem.

## How to disable firmware signature checking

Change "`n`" in `version.txt` to "`y`" like this: `0_88_1908091810_c695ccd_eclipse_y`. Than replace old `version.txt` MD5 hash with new in `md5.txt`.