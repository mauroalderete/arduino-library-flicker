# CHANGELOG

## v1.0.1 - 20200907

Se modifico el proyecto para ajustarlo a las convenciones de librerias de Arduino y a las convenciones de C++.

Se agrego documentación sobre el uso de la libreria y se armo un ejemplo sencillo de uso.

Se agregaron instrucciones en el README.md para la instalación, actualización y selección de version de la libreria utilizando las utilizades que ofrece git

## v1.0.0 - 20200202

Creacion de libreria Flicker

Se utiliza una clase Flicker junto a un enum class FlickerState para monitorear el estado del parpadeo. La clase manipula un solo parpadeo, por lo que para manipular varios salidas parpadeantes se deben instanciar tantos objetos de la clase como salidas deseadas.
