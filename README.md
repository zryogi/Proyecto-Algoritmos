# Proyecto de Algoritmos

Visualizador de algoritmos de ordenamiento

## Instalacion

### Windows

Este proyecto usa [raylib](https://www.raylib.com/) para dibujar en pantalla, asi que asegurese de tenerlo instalado.
Despues clone el repositorio

```sh
git clone https://github.com/matwate/Proyecto-Algoritmos.git
```

Despues de clonarlo encontrara un archivo `main.code-workspace`, abralo en vscode y oprima el boton `open workspace`

Una vez eso ya puede ejecutar el programa con `F5`

### Linux/MacOS

1. Clona el repositorio y navega al directorio principal:
    ```bash
    git clone <url-del-repositorio>
    cd visualizador-algoritmos
    ```

2. Compila el proyecto utilizando **Makefile**:
    ```bash
    make
    ```

3. Ejecuta la aplicación:
    ```bash
    make run
    ```

---

## Caracteristicas

- **Visualización algoritmos de ordenamiento**:

  - Insertion Sort
  - Selection Sort
  - Bubble Sort
  - Quick Sort
  - Merge Sort
  - Heap Sort
  - Radix LSD Sort
  - Bogo Sort.

  Y se puede cambiar el tamaño del arreglo sobre el cual Bogo Sort trabaja.

- **Visualización de árboles**: Inserciones, recorridos (inorden, preorden, posorden), y balanceo.
- **Exploración de grafos**: BFS, DFS, Dijkstra, y generación de grafos aleatorios.

---

## Demos

### Algoritmos de Ordenamiento

#### Bubble Sort
<video controls width="600">
  <source src="demos/sort/bubble.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Heap Sort
<video controls width="600">
  <source src="demos/sort/heap.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Insertion Sort
<video controls width="600">
  <source src="demos/sort/insertion.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Quick Sort
<video controls width="600">
  <source src="demos/sort/quick.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Radix Sort (LSD)
<video controls width="600">
  <source src="demos/sort/radix.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Selection Sort
<video controls width="600">
  <source src="demos/sort/selection.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

---

### Visualización de Árboles

#### Inserción de Nodo Aleatorio
<video controls width="600">
  <source src="demos/trees/random_node_tree.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Recorrido Inorden
<video controls width="600">
  <source src="demos/trees/inorder.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Recorrido Preorden
<video controls width="600">
  <source src="demos/trees/preorder.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Recorrido Posorden
<video controls width="600">
  <source src="demos/trees/posorder.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Balanceo del Árbol
<video controls width="600">
  <source src="demos/trees/balance_tree.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

---

### Visualización de Grafos

#### Búsqueda BFS
<video controls width="600">
  <source src="demos/graph/bfs.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Búsqueda DFS
<video controls width="600">
  <source src="demos/graph/dfs.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Algoritmo de Dijkstra
<video controls width="600">
  <source src="demos/graph/djikstra.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Generación de Grafo Aleatorio
<video controls width="600">
  <source src="demos/graph/random_graph.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

#### Creación de Grafo Personalizado
<video controls width="600">
  <source src="demos/graph/custom_graph.webm" type="video/webm">
  Tu navegador no soporta videos en formato WebM.
</video>

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
