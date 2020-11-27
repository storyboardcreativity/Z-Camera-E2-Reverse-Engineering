# Z-Camera-E2-Reverse-Engineering
Here you can find my Z-CAM E2 firmware reverse-engineering results.

## Original Firmwares

*Z-CAM very often delete links to old firmware versions on the official website, so I have to make copies for you in order not to lose them forever.*

| Version | E2 | E2C | E2-M4 | E2G | E2-S6 | E2-F6 | E2-F8 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0.82 | **E** | X | X | X | X | X | X |
| 0.83 | [**DL**](https://drive.google.com/file/d/1jJrGkIRqN6eE69jOVe1uhc4U9xCBTOPn) | X | X | X | X | X | X |
| 0.84 | **E** | X | X | X | X | X | X |
| 0.86 | **E** | X | X | X | X | X | X |
| 0.87 | [**DL**](https://drive.google.com/file/d/1289_f3ajGz-suU9szCGJV_OVd_9r2uzm) | X | X | X | X | X | X |
| 0.88 | [**DL**](https://drive.google.com/file/d/1HfqmnN68fDevtR8M-nH95Obtq-OF6o2E) | U | X | X | X | X | X |
| 0.89 | **E** | **E** | X | X | X | X | X |
| 0.93 | [**DL**](https://drive.google.com/file/d/11YstktVFOt_yOj3CWSuSffHIsagfVKpt) | **E** | X | **E** | **E** | **E** | **E** |
| 0.94 | [**DL**](https://drive.google.com/file/d/1g2v4HXRimdkgN7cOArdvZeewZHafO5tc) | **E** | X | **E** | **E** | **E** | **E** |
| 0.95 | [**DL**](https://drive.google.com/file/d/1aTrBeZbWnp2k42D8fWuU3paYSE0iutyv) | **E** | X | **E** | **E** | **E** | **E** |
| 0.96 | [**DL**](https://drive.google.com/file/d/1DjjVKM5Oy5I5vOAyyXAKkuScftbOXqeZ) | **E** | **E** | X | **E** | **E** | **E** |
| 0.97 | [**DL**](https://drive.google.com/file/d/1igY1f6xUmuhEWwV6j8IypGeL-nhp4chF) | [**DL**](https://drive.google.com/file/d/10uI2smsQGYgBsFFAERJasMwDrE02VjMk) | [**DL**](https://drive.google.com/file/d/1Ddukjq3QJggGJDSvV0rqrvlCaAs3NNzM) | [**DL**](https://drive.google.com/file/d/1OQnNIiD_fmy5N6AXrPKu32hEZklG4N40) | [**DL**](https://drive.google.com/file/d/1imYk0DfRXVHeyqJJ1vggHLfdmRByJJOF) | [**DL**](https://drive.google.com/file/d/1DPGzTaCEEQyAnt7QU3MCifV6rjvAW5Zg) | [**DL**](https://drive.google.com/file/d/1HdtIaZ9XIFx5nFmEaK0Hehij6EVp-hzp) |
| 0.97.1 | [**DL**](https://drive.google.com/file/d/1Vp1x7MhtYsIhUIgGep1ZX3zutS3AanU8) | [**DL**](https://drive.google.com/file/d/16qLAsOQNT_SNFYuSKrE2wNoIA47Ej0oX) | [**DL**](https://drive.google.com/file/d/1ZSLHlU8PaHovMF3occNHyd5mvIg5gP1x) | [**DL**](https://drive.google.com/file/d/1QGN0d2cJfvkPznCpVnHsH4ICZIzv--fT) | [**DL**](https://drive.google.com/file/d/1RHaN0Df6xYmtW_w8USCdXUJ7Eao5wwwm) | [**DL**](https://drive.google.com/file/d/1NTQNwp1CqlX5PepemH_h9Nifs-5_SOKb) | [**DL**](https://drive.google.com/file/d/1AZqEom5JhsMikOu17mD-yJdOyvEGortr) |

#### Legend

`DL` : firmware file download link

`X` : does not exist

`E` : exists, but no download link for now

`U` : I don't know if it exists or not

## AES encryption

Z-CAM use AES (128-bit) CFB encryption for main firmware data ZIP-archive (**update_data.bin**).

| E2 firmware version | AES key (hex bytes) | AES initial vector (hex bytes) |
|:---:|:---:|:---:|
| 0.83 | X | X |
| 0.87 | ```53 7E 15 16``` </br> ```28 AE D2 A6``` </br> ```AB F7 15 88``` </br> ```09 CF 22 3C``` | ```00 01 02 03``` </br> ```04 05 06 07``` </br> ```08 09 0A 0B``` </br> ```0C 0D 0E 0F``` |
| 0.88 | ```53 7E 15 16``` </br> ```28 AE D2 A6``` </br> ```AB F7 15 88``` </br> ```09 CF 22 3C``` | ```00 01 02 03``` </br> ```04 05 06 07``` </br> ```08 09 0A 0B``` </br> ```0C 0D 0E 0F``` |
| 0.93 | ```53 7E 15 16``` </br> ```28 AE D2 A6``` </br> ```AB F7 15 88``` </br> ```09 CF 22 3C``` | ```00 01 02 03``` </br> ```04 05 06 07``` </br> ```08 09 0A 0B``` </br> ```0C 0D 0E 0F``` |
| 0.96 | ```CF 55 5B B7``` </br> ```BF 0E 45 6E``` </br> ```94 10 D0 15``` </br> ```D7 5F E3 5B``` | ```00 01 02 03``` </br> ```04 05 06 07``` </br> ```08 09 0A 0B``` </br> ```0C 0D 0E 0F``` |

#### Legend

`X` : encryption is not used

## Passwords for archives in firmware

Here are passwords that are user for each encrypted ZIP-archive (for example, **recovery.zip** or **update_data.zip**):

| Version | ZIP password |
|:---:|:---:|
| 0.83 | gmi!!emoclew |
| 0.87 | gmi!!emoclew |
| 0.93 | gmi!!emoclew |
| 0.94 | gmi!!emoclew |
| 0.96 | 1234564698742 |

## Hardware

| Model | SoC | Sensor |
|:---:|:---:|:---:|
| E2 | HiSilicon Hi3559A V100 | Sony IMX299 |
| E2C | unknown (HiSilicon) | Sony IMX159 |
| E2G | unknown | Sony IMX344 |
| E2-S6 | unknown | Sony IMX571 |
| E2-F6 | unknown | Sony IMX410 |
| E2-F8 | unknown (HiSilicon) | Sony IMX455 |

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

## How to make your own firmware?

### On Linux:

#### 1. Download official firmware file

You can find firmware file links on Z-CAM official web-site or on this page (watch "Original Firmwares" section above).

#### 2. Unpack firmware file as ZIP-archive
#### 3. Decrypt update_data.bin file to update_data.zip

Use my update_data_crypter tool to decrypt update_data.zip for your firmware version. Example:
`/<path_to_crypter>/crypter -d -v0.96 -i update_data.bin -o update_data.zip`

#### 4. Unpack update_data.zip
#### 5. Unpack RootFS

`mkdir rootfs`
`tar -xzf rootfs.tar.gz -C rootfs`

#### 6. Make any changes in unpacked RootFS you want

You know what to do here :)

#### 7. Pack RootFS

`cd rootfs`
`tar -czvf ./../rootfs.tar.gz *`

#### 8. Pack update_data.zip



#### 9. Encrypt update_data.zip file to update_data.bin

Use my update_data_crypter tool to encrypt update_data.zip for your firmware version. Example:
`/<path_to_crypter>/crypter -e -v0.96 -i update_data.zip -o update_data.bin`

#### 10. Recalculate MD5 for update_data.bin
#### 11. Force firmware signature checking bypass

Change last symbol in version.txt from "n" to "y"

#### 12. Pack firmware to uncompressed ZIP