from flask import Flask, request
import os
import shutil
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

app = Flask(__name__)

class MyHandler(FileSystemEventHandler):
    def on_created(self, event):
        if event.src_path.endswith('datos_grafo.txt'):
            # Ruta de la carpeta de descargas
            carpeta_descargas = os.path.expanduser('~/Downloads')
            # Ruta completa del archivo a mover
            archivo_a_mover = os.path.join(carpeta_descargas, 'datos_grafo.txt')
            # Ruta de la carpeta de destino
            carpeta_destino = "C:/Users/ASUS/OneDrive/Documentos/Gomory-Hu-Tree/"
            # Mover el archivo a la carpeta de destino
            shutil.move(archivo_a_mover, carpeta_destino)

event_handler = MyHandler()
observer = Observer()
observer.schedule(event_handler, path=os.path.expanduser('~/Downloads'), recursive=False)
observer.start()

if __name__ == '__main__':
    app.run(debug=True)