import tkinter as tk
from tkinter import messagebox
import json
import networkx as nx
import matplotlib.pyplot as plt

def agregar_arista():
    if len(entry_aristas) < int(entry_cantidad_aristas.get()):
        # Crear entradas para una nueva arista
        entry_aristas.append((tk.Entry(frame_aristas), tk.Entry(frame_aristas), tk.Entry(frame_aristas)))
        for j, entry in enumerate(entry_aristas[-1]):
            entry.grid(row=len(entry_aristas), column=j, padx=5, pady=5)
    else:
        messagebox.showerror("Error", "Ya ha alcanzado la cantidad máxima de aristas.")

def obtener_datos():
    cantidad_aristas = len(entry_aristas)
    cantidad_vertices = int(entry_cantidad_vertices.get())

    # Obtener las aristas y sus pesos
    aristas = []
    for i in range(cantidad_aristas):
        vertice1 = int(entry_aristas[i][0].get())
        vertice2 = int(entry_aristas[i][1].get())
        peso = int(entry_aristas[i][2].get())
        aristas.append((vertice1, vertice2, peso))

    # Guardar los datos en un archivo JSON
    datos = {
        "cantidad_aristas": cantidad_aristas,
        "cantidad_vertices": cantidad_vertices,
        "aristas": aristas
    }
    with open("datos.json", "w") as file:
        json.dump(datos, file)

    messagebox.showinfo("Datos guardados", "Los datos han sido guardados en 'datos.json'.")

    # Convertir los datos a formato de texto plano
    txt_data = f"{cantidad_aristas} {cantidad_vertices}\n"
    for arista in aristas:
        txt_data += " ".join(map(str, arista)) + "\n"

    # Guardar los datos en un archivo de texto
    with open("datos.txt", "w") as file:
        file.write(txt_data)
    messagebox.showinfo("Datos guardados", "Los datos han sido guardados en 'datos.txt'.")

def obtener_datos():
    try:
        # Leer los datos desde el archivo de texto
        with open("datos.txt", "r") as file:
            lines = file.readlines()

        # Obtener la cantidad de aristas y vértices
        cantidad_aristas, cantidad_vertices = map(int, lines[0].split())

        # Obtener las aristas y sus pesos
        aristas = []
        for line in lines[1:]:
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
        plt.show()

    except FileNotFoundError:
        messagebox.showerror("Error", "El archivo de datos 'datos.txt' no fue encontrado.")


# Crear la ventana principal
root = tk.Tk()
root.title("Ingresar datos de aristas")
root.geometry("400x300")

# Frame para las aristas
frame_aristas = tk.Frame(root)
frame_aristas.pack(pady=10)

# Etiqueta y entrada para la cantidad de aristas
label_cantidad_aristas = tk.Label(root, text="Cantidad de aristas:")
label_cantidad_aristas.pack()
entry_cantidad_aristas = tk.Entry(root)
entry_cantidad_aristas.pack()

# Etiqueta y entrada para la cantidad de vértices
label_cantidad_vertices = tk.Label(root, text="Cantidad de vértices:")
label_cantidad_vertices.pack()
entry_cantidad_vertices = tk.Entry(root)
entry_cantidad_vertices.pack()

# Crear botón para agregar arista
button_agregar_arista = tk.Button(root, text="Agregar Arista", command=agregar_arista, bg="lightblue", font=("Arial", 10), bd=0, borderwidth=2, relief="groove", width=15)
button_agregar_arista.pack(pady=10)

# Crear botón para obtener los datos y dibujar el grafo
button_obtener_datos = tk.Button(root, text="Obtener Datos y Dibujar Grafo", command=obtener_datos, bg="lightblue", font=("Arial", 10), bd=0, borderwidth=2, relief="groove", width=25)
button_obtener_datos.pack(pady=10)

# Lista para almacenar las entradas de las aristas
entry_aristas = []

# Ejecutar el bucle de eventos
root.mainloop()


