# Como construir:

## Dependencias:

### Com Dev Containers:

* docker
* uma IDE com suporte ao [dev containers](https://containers.dev/)

### Sem Dev Containers:

* cmake
* opengl
* freeglut
* sdl2_image
* libdevil
* lib3ds

## Construir:

```sh
git clone https://github.com/talle5/GLUTdoZero.git
cd GLUTdoZero
cmake -S . -B build
ninja -C build
```

binário final em: build/GLUTdoZero.bin
