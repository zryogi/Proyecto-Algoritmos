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
A continuación, se presentan videos demostrativos de los algoritmos de ordenamiento implementados:

- [Bubble Sort](demos/sort/bubble.webm)
- [Heap Sort](demos/sort/heap.webm)
- [Insertion Sort](demos/sort/insertion.webm)
- [Quick Sort](demos/sort/quick.webm)
- [Radix Sort (LSD)](demos/sort/radix.webm)
- [Selection Sort](demos/sort/selection.webm)

### Visualización de Árboles
Ejemplos de operaciones realizadas en árboles:

- [Inserción de Nodo Aleatorio](demos/trees/random_node_tree.webm)
- [Recorrido Inorden](demos/trees/inorder.webm)
- [Recorrido Preorden](demos/trees/preorder.webm)
- [Recorrido Posorden](demos/trees/posorder.webm)
- [Balanceo del Árbol](demos/trees/balance_tree.webm)

### Visualización de Grafos
Explora diferentes algoritmos y operaciones con grafos:

- [Búsqueda BFS](demos/graph/bfs.webm)
- [Búsqueda DFS](demos/graph/dfs.webm)
- [Algoritmo de Dijkstra](demos/graph/djikstra.webm)
- [Generación de Grafo Aleatorio](demos/graph/random_graph.webm)
- [Creación de Grafo Personalizado](demos/graph/custom_graph.webm)

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
