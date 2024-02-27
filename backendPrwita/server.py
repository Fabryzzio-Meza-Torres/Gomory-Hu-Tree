#importar flask
from flask import Flask, request, jsonify

import json
#cors
from flask_cors import CORS
import os
import sys
import time
import networkx as nx
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

app = Flask(__name__)

#cors, permitir peticiones desde cualquier origen
CORS(app)


@app.route('/api/v1/grafo', methods=['POST'])
def upload():
    try:
        data = request.json
        print(data)
        txtContent = data['cantidadVertices'] + " " + data['cantidadAristas'] + "\n" + data['aristas']

        with open("backendPrwita/static/cpp/datos_grafo.txt", "w") as file:
            file.write(txtContent)
            file.close()

        # ejecutar el codigo c++
        ruta = os.path.join(os.getcwd(), "backendPrwita", "static", "cpp", "GomoryHuTree.exe")
        print(ruta)
        #eliminar el output.txt
        try:
            os.remove("backendPrwita/static/cpp/output.txt")
        except:
            pass

        #ejecutar el programa
        os.system(ruta)

        #esperar a que se cree el archivo
        while not os.path.exists("backendPrwita/static/cpp/output.txt"):
            pass

        output = ""
        #leer el archivo
        with open("backendPrwita/static/cpp/output.txt", "r") as file:
            output = file.read()
            file.close()


        #crear el grafo original
        G = nx.Graph()
        aristas = data['aristas'].split("\n")
        print(aristas)
        for arista in aristas:
            arista = arista.split(" ")
            if len(arista) == 3:
                G.add_edge(arista[0], arista[1], weight=arista[2])

        pos = nx.spring_layout(G)  # Posiciones de los nodos
        nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue', font_size=10, font_weight='bold')  # Dibujamos el grafo
        labels = nx.get_edge_attributes(G, 'weight')  # Obtenemos los pesos de las aristas
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)  # Dibujamos los pesos
        plt.title(f"Grafo Original")
        plt.savefig(f"backendPrwita/static/grafo_original.png")  # Guardar la figura como imagen
        plt.close()

        #crear el arbol de gomory-hu
        G = nx.Graph()
        aristas = output.split("\n")
        for arista in aristas:
            arista = arista.split(" ")
            if len(arista) == 3:
                G.add_edge(arista[0], arista[1], weight=arista[2])
        
        pos = nx.spring_layout(G)  # Posiciones de los nodos
        nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue', font_size=10, font_weight='bold')  # Dibujamos el grafo
        labels = nx.get_edge_attributes(G, 'weight')  # Obtenemos los pesos de las aristas
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)  # Dibujamos los pesos
        plt.title(f"Arbol de Gomory-Hu")
        plt.savefig(f"backendPrwita/static/arbol_gomory_hu.png")  # Guardar la figura como imagen
        plt.close()
        

    except Exception as e:
        print(e)
        return jsonify({'msg': 'Error al procesar la solicitud'}), 500
    
    return jsonify({'grafoOriginal': 'http://localhost:5000/static/grafo_original.png', 'arbolGomoryHu': 'http://localhost:5000/static/arbol_gomory_hu.png'}), 200
pass

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)