# Z-Camera-E2-Reverse-Engineering
Here you can find my Z Camera E2 firmware reverse-engineering results.

## Original Firmwares

*Z-CAM very often delete links to old firmware versions on the official website, so I have to make copies for you in order not to lose them forever.*

| Version | E2 | E2C | E2-M4 | E2G | E2-S6 | E2-F6 | E2-F8 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0.82 | **E** | X | X | X | X | X | X |
| 0.83 | [**download**](https://drive.google.com/file/d/1jJrGkIRqN6eE69jOVe1uhc4U9xCBTOPn) | X | X | X | X | X | X |
| 0.84 | **E** | X | X | X | X | X | X |
| 0.86 | **E** | X | X | X | X | X | X |
| 0.87 | [**download**](https://drive.google.com/file/d/1289_f3ajGz-suU9szCGJV_OVd_9r2uzm) | X | X | X | X | X | X |
| 0.88 | [**download**](https://drive.google.com/file/d/1HfqmnN68fDevtR8M-nH95Obtq-OF6o2E) | U | X | X | X | X | X |
| 0.89 | **E** | **E** | X | X | X | X | X |
| 0.93 | **E** | **E** | X | **E** | **E** | **E** | **E** |
| 0.94 | **E** | **E** | X | **E** | **E** | **E** | **E** |
| 0.95 | **E** | **E** | X | **E** | **E** | **E** | **E** |
| 0.96 | [**download**](https://drive.google.com/file/d/1DjjVKM5Oy5I5vOAyyXAKkuScftbOXqeZ) | **E** | **E** | X | **E** | **E** | **E** |

#### Legend

`X` : does not exist

`E` : exists, but no download link for now

`U` : I don't know if it exists or not


## Passwords for archives in firmware

Here are passwords that are user for each encrypted ZIP-archive (for example, **recovery.zip** or **update_data.zip**):

| Version | ZIP password |
|:---:|:---:|
| 0.83 | gmi!!emoclew |
| 0.87 | gmi!!emoclew |
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