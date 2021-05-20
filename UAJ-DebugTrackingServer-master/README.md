# Servidor de pruebas del sistema de telemetría

Implementación de un servidor de prueba muy sencillo para conectar con él el sistema de telemetría desarrollado en la práctica 3 de Usabilidad y Análisis de Juegos. Está implementado en Python y Flask y guarda en un fichero las trazas que se van enviando.

**Este servidor es solo para hacer pruebas para la práctica. No es seguro y tiene múltiples deficiencias por lo que no es conveniente usarlo en producción.**

Es necesario Python 3 para poder ejecutarlo. Para no "ensuciar" la instalación global de Python podemos hacer uso de un entorno virtual:

1. Creamos el entorno virtual: `virtualenv .venv` o `python -m venv .venv`
2. Activamos dicho entorno virtual: `source .venv/bin/activate`
3. Instalamos los requisitos con `pip install -r requirements.txt`
4. Ejecutamos el servidor con `python app/main.py`

El fichero `setup-run.sh` hace todos los pasos descritos anteriormente.

El servidor queda a la escucha en `localhost:8080`. Hay un punto de acceso con el que enviar nuevas trazas y ver las trazas almacenadas:

- GET `localhost:8080/tracker`: devuelve una lista con las trazas almacenadas
- POST `localhost:8080/tracker`: almacena la cadena de la traza en el servidor. La traza se puede enviar en dos formatos diferentes:

    - `text/plain`: Una cadena en texto plano.
    - `application/json`: un objeto con el siguiente aspecto:

```
{
    "data": "..."
}
```


