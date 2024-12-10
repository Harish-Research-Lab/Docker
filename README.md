# Docker containers
This repository provides the docker files and the links to docker images from dockerHub. These docker images have been created for usage of the lab members to develop numerical methods and enhance reproducibility of the developed methods. We are always interested to help you if you would like to use our software or reproduce the results from our paper. 

Each of the docker images are documented in the particular folders. These docker images are based on Ubuntu base OS. We aim to add more images in the future. If there is something of interest, please feel free to contact us. 

For more information about our research, please feel free to check our website www.harishlab.com. If you would like help and would like to use our images, please feel free to reachout to us at Ajay.Harish@manchester.ac.uk.

## Fortran
The `Fortran` folder contains the information about this image and also the instructions to run this image. The image is available through dockerhub (https://hub.docker.com/r/harishlab/fortran).

## Creating new custom docker containers
You can create multi-platform images and push to dockerhub by going into the folder and using the command
`docker buildx build \
 --tag harishlab/fortran:1.0.0 \
 --platform linux/arm/v7,linux/arm64/v8,linux/amd64 \
 --builder container \
 --push .` (There is a . at the end. Do not miss that!)

In order to build other images of interest to you, replace:
- `harishlab` with your own Docker username.
- `fortran:1.0.0` with your own name of the image and version number.