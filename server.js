const express = require('express');
const fs = require('fs');
const path = require('path');

const app = express();
const port = 3000;

// Servir el archivo index.html estático desde la misma carpeta
app.use(express.static(path.join(__dirname)));

app.use(express.urlencoded({ extended: true }));

app.post('/convert', (req, res) => {
  const vertices = parseInt(req.body.vertices);
  const aristas = parseInt(req.body.aristas);
  const aristasData = req.body.aristasData.trim().split('\n').map(line => line.split(' '));

  let textoConvertido = `${vertices} ${aristas}\n`;

  aristasData.forEach(arista => {
    if (arista.length === 3) {
      textoConvertido += `${arista[0]} ${arista[1]} ${arista[2]}\n`;
    }
  });

  fs.writeFile('input.txt', textoConvertido, (err) => {
    if (err) {
      console.error('Error al escribir el archivo:', err);
      res.status(500).send('Error interno del servidor');
      return;
    }
    console.log('El texto se ha guardado en "input.txt"');
    res.download('input.txt'); // Enviar el archivo descargado al cliente
  });
});

app.listen(port, () => {
  console.log(`Servidor corriendo en http://localhost:${port}`);
});

