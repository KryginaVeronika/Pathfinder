#include "../inc/pathfinder.h"

#define NO_PARENT -1


bool is_has_index(int a, int* arr, int size) {
    for(int i = 0; i < size; i++) {
        if(a == arr[i]) {
            return true;
        }
    }
    return false;
}

bool is_reverse_path(int start_1, int end_1, int start_2, int end_2) {
   if(start_1 == end_2 && end_1 == start_2) {
        return true;
   }
   return false;
}

bool path_is_unique(int *new_path, int**path_array, int island_num) {

    bool found = false;
    int indexes_in_new_path = 0;
    for(int i = 0; i < island_num && !found; i++) {
        if(new_path[i + 1] == -2 || i + 1 == island_num) {
            indexes_in_new_path = i;
            found = true;
            break;
        }
    }

    bool next = false;
    for(int i = 0; path_array[i][0] != -1 && i < island_num*island_num; i++) {
        if(is_reverse_path(path_array[i][0], path_array[i][indexes_in_new_path],  new_path[0],  new_path[indexes_in_new_path])) {
            if(island_num != indexes_in_new_path) {
                if(path_array[i][indexes_in_new_path + 1] == -1){
                    for(int j = 1; j < indexes_in_new_path - 1; j++){
                        if(!is_has_index(path_array[i][j], new_path, island_num)) {
                            next = true;
                        }
                    }
                    if(!next) {
                        return false;
                    }
                }
            } else if(island_num == indexes_in_new_path) {
                for(int j = 1; j < indexes_in_new_path - 1; j++){
                        if(!is_has_index(path_array[i][j], new_path, island_num)) {
                            next = true;
                        }
                    }
                    if(!next) {
                        return false;
                    }
            }

        }
    }
    return true;
}

int* mx_initialize_new_path(int currentVertex, int parents[], int island_num) {
    int stack[island_num];
    int top = -1;
    int *new_path = malloc(sizeof(int) * island_num);
    for(int i = 0; i < island_num; i++) {
        new_path[i] = -2;
    }
    int index = 0;

    while (currentVertex != NO_PARENT) {
        stack[++top] = currentVertex;
        currentVertex = parents[currentVertex];
    }

    while (top >= 0) {
        new_path[index++] = stack[top--];
    }

    return new_path;
}

int** create_paths_array(int src, int distances[], int parents[], int island_num, int**path_array) {

    //changeee
    int **paths = (int**)malloc(sizeof(int*) * (mx_pow(island_num, 2)));
    
    for(int i = 0; i < island_num*island_num; i++) {
        paths[i] = (int*)malloc(sizeof(int) * (island_num + 1));
        for(int j = 0; j < island_num + 1; j++) {
            paths[i][j] = -1;
        }
    }

    
    int path_index = 0;
    for (int vertexIndex = 0; vertexIndex < island_num; vertexIndex++) {
        if (vertexIndex != src) {
            int* new_path = mx_initialize_new_path(vertexIndex, parents, island_num);

            if(path_is_unique(new_path, path_array, island_num)) { 
                for(int i = 0; new_path[i] != -2 && i < island_num; i++) {
                    paths[path_index][i] = new_path[i];
                }
                
                paths[path_index][island_num + 1] = distances[vertexIndex];
                path_index++;
            
            }
            free(new_path);
        }
    }


    return paths;
}

int **dijkstra(int **graph, int src, int island_num, int**path_array) {
    // Масив, що зберігає найкоротші відстані від джерела до кожного вузла
    int shortestDistances[island_num];

    // Масив для відстеження того, чи вже додано вузол до множини найкоротших шляхів
    bool added[island_num];

    // Ініціалізація масивів для кожного вузла
    for (int vertexIndex = 0; vertexIndex < island_num; vertexIndex++) {
        shortestDistances[vertexIndex] = INT_MAX; // Початкова відстань встановлена як нескінченність
        added[vertexIndex] = false; // Жоден вузол не доданий до множини найкоротших шляхів
    }

    // Відстань до джерела (src) встановлена як 0
    shortestDistances[src] = 0;

    // Масив для визначення "батьківських" вузлів в оптимальному шляху
    int parents[island_num];

    // Батьківський вузол для джерела (src) встановлений як NO_PARENT
    parents[src] = NO_PARENT;

    // Знаходження найкоротших шляхів
    for (int i = 1; i < island_num; i++) {
        int nearestVertex = -1;
        int shortestDistance = INT_MAX;

        // Пошук найближчого вузла, який ще не додано
        for (int vertexIndex = 0; vertexIndex < island_num; vertexIndex++) {
            if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance) {
                nearestVertex = vertexIndex;
                shortestDistance = shortestDistances[vertexIndex];
            }
        }

        // Позначення, що найближчий вузол тепер доданий
        added[nearestVertex] = true;

        // Оновлення відстаней та "батьківських" вузлів для сусідніх вузлів
        for (int vertexIndex = 0; vertexIndex < island_num; vertexIndex++) {
            int edgeDistance = graph[nearestVertex][vertexIndex];
            if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex])) {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
            }
        }
    }
        int** paths = create_paths_array(src, shortestDistances, parents, island_num, path_array);

        return paths;
}
