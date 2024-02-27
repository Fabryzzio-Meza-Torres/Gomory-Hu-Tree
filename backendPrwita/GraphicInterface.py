import os
import time
import networkx as nx
import matplotlib.pyplot as plt

def dibujar_grafo(archivo, guardar_imagen=False):
    try:
        # Leer los datos desde el archivo de texto
        with open(archivo, "r") as file:
            lines = file.readlines()

        # Obtener las aristas y sus pesos
        aristas = []
        for line in lines:
            datos_arista = list(map(int, line.split()))
            aristas.append((datos_arista[0], datos_arista[1], datos_arista[2]))

        # Crear el grafo y dibujarlo
        G = nx.Graph()
        for arista in aristas:
            G.add_edge(arista[0], arista[1], weight=arista[2])  # Añadimos el peso como atributo 'weight'
        pos = nx.spring_layout(G)  # Posiciones de los nodos
        nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue', font_size=10, font_weight='bold')  # Dibujamos el grafo
        labels = nx.get_edge_attributes(G, 'weight')  # Obtenemos los pesos de las aristas
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)  # Dibujamos los pesos
        plt.title(f"Grafo de {archivo}")

        if guardar_imagen:
            plt.savefig(f"{archivo}_grafo.png")  # Guardar la figura como imagen

        plt.show()

    except FileNotFoundError:
        print(f"Error: El archivo de datos '{archivo}' no fue encontrado.")

def eliminar_primera_linea(archivo_original, archivo_nuevo):
    try:
        with open(archivo_original, "r") as f:
            lines = f.readlines()
        with open(archivo_nuevo, "w") as f:
            f.writelines(lines[1:])
    except FileNotFoundError:
        print(f"Error: El archivo '{archivo_original}' no fue encontrado.")

def obtener_datos():
    try:
        # Esperar a que se cree el archivo output.txt
        while not os.path.exists("output.txt"):
            time.sleep(1)  # Esperar 1 segundo antes de verificar nuevamente

        # Eliminar la primera línea del archivo datos_grafo.txt
        eliminar_primera_linea("datos_grafo.txt", "datos_grafo_temp.txt")

        # Dibujar el grafo del archivo datos_grafo_temp.txt
        dibujar_grafo("datos_grafo_temp.txt", guardar_imagen=True)

        # Leer el archivo output.txt
        with open("output.txt", "r") as file:
            lines = file.readlines()

        # Dibujar el grafo del archivo output.txt
        dibujar_grafo("output.txt", guardar_imagen=True)

    except FileNotFoundError:
        print("Error: El archivo de datos 'output.txt' no fue encontrado.")

# Eliminar un output.txt si existe
if os.path.exists("output.txt"):
    os.remove("output.txt")

# Crear una carpeta con sys
os.system("C:/Users/ASUS/OneDrive/Documentos/Gomory-Hu-Tree/backendPrwita/static/cpp/GomoryHuTree.exe")

# Obtener los datos y dibujar el grafo
obtener_datos()




