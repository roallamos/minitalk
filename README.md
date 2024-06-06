# Minitalk

## Descripción

Minitalk es un proyecto del curso de la Escuela 42 que tiene como objetivo implementar un sistema de comunicación simple entre dos programas, un cliente y un servidor, utilizando señales de UNIX. El cliente envía un mensaje de texto al servidor, y el servidor lo muestra en su salida estándar.

## Características

- Comunicación cliente-servidor mediante señales.
- Envío y recepción de mensajes de texto.

## Requisitos

- Sistema operativo: Linux.
- Compilador compatible con C.

## Instalación

1. Clona este repositorio:
    ```sh
    git clone https://github.com/roallamos/minitalk.git
    ```
2. Navega al directorio del proyecto:
    ```sh
    cd minitalk
    ```
3. Compila los programas cliente y servidor:
    ```sh
    make
    ```

## Uso

1. Ejecuta el servidor:
    ```sh
    ./server
    ```
2. Ejecuta el cliente, pasando como argumento el PID del servidor y el mensaje a enviar:
    ```sh
    ./client [PID del servidor] [mensaje]
    ```

Ejemplo:
```sh
./client 12345 "Hola, servidor!"
