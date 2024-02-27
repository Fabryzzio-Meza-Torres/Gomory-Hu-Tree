import shutil
import os
# Ruta del archivo a mover
archivo_a_mover = "C:/Users/ASUS/OneDrive/Documentos/Gomory-Hu-Tree/backendPrwita/static/cpp/datos_grafo.txt"

# Ruta de la carpeta de destino
carpeta_destino = "C:/Users/ASUS/OneDrive/Documentos/Gomory-Hu-Tree/backendPrwita/static"

# Ruta completa del archivo de destino
ruta_destino = os.path.join(carpeta_destino, "datos_grafo.txt")

# Copiar el archivo a la carpeta de destino, sobrescribiendo si ya existe
shutil.copy2(archivo_a_mover, carpeta_destino)

# Eliminar el archivo original
os.remove(archivo_a_mover)