# Ejemplo de envío y recepción de mensajes mediante UDP

Sencillo ejemplo de cómo enviar mensajes entre un cliente y un servidor utilizando UDP. Los mensajes consisten de un cadena de texto (finalizada mediante `\0`). El servidor imprime los mensajes por la salida estándar. Por brevedad los programas no implementan control de errores.

## Cliente y Servidor separados

El programa `client.c` implementa el cliente. Requiere como argumentos la dirección del servidor (IP y puerto) y el mensaje a enviar. Por ejemplo `./cliente 127.0.0.1 9999 hola` envia `hola` al servidor (incluyendo el `\0`).

El programa `server.c` implementar el servidor. Requiere como argumento el puerto en el que recibirá los mensajes. Por ejemplo `./server 9999` ejecuta el servidor e indica que espere mensajes por el puerto `9999`.

## Cliente y Servidor en un mismo programa

El programa `udpmsg.c` implementa el cliente y el servidor en el mismo programa. Para ejecutar en modo servidor se utiliza el parámetro `-s` y para ejecutar como cliente, el argumento `-c`.

Por ejemplo, para iniciar el servidor en el puerto 9999 se ejecuta `./udpmsg -s 9999`. Para enviar mensajes con el cliente, se ejecuta `./udpmsg -c 127.0.0.1 9999 hola`.
