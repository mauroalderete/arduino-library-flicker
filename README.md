# Flicker

Libreria de arduino para generar una salida parpadeante sin bloquear el flujo del codigo. Utiliza la funcion millis de Arduino.h

## Instalación

Utilizando la consola de tu preferencia, dirigete a la ruta de las librerias de arduino de tu instalacion. Por ejemplo:

``` bash
cd P:\Arduino\libraries
```

Una vez dentro del directorio solo basta con clonar el proyecto de la libreria en la versión que gustes.

``` bash
git clone git@gitlab.com:arduinolibraries/Flicker.git .
```

Esto creara el directorio Flicker de la libreria junto con los archivos de documentación y los ejemplos.

## Seleccion de versión

Por defecto, luego de instalar desde el repositorio, la versión seleccionada es la ultima vigente en master. Si quiere puede seleccionar otra version en cualquier momento utilizando los comandos git checkout y haciendo referencia a la versión que desee.

``` bash
git checkout tag/<versión>
```

Puede ver un listado de las versiones disponibles por medio del siguiente comando

``` bash
git fetch --tags
```

## Actualización

Para actualizar a la ultima versión solo es necesario ejecutar un simple pull

``` bash
git pull
```

Luego podra seleccionar la ultima versión siguiendo los pasos de Selección de versión

## Uso

El uso es sencillo, basta con instanciar un objeto de la clase Flicker y con figurar el pin del parpadeo y el intervalo dentro de los parametros de su constructor.

``` c++
Flicker flick(2, 1000);
```

Luego se inicia el parpadeo ejecutando el metodo **Start()**

``` c++
flick.Start();
```

Es obligatorio que se realice una llamada al metodo **Loop()** dentro del bucle infinito del procesador para que Flicker sea capaz de calcular los intervalos de tiempos y alternar el estado del pin de salida.

``` c++
void loop(){
    flick.Loop();
}
```

## Links

[Cambios de version](CHANGELOG.md)
[Repositorio](https://gitlab.com/arduinolibraries/Flicker/-/tree/master)