

#include <vector>
#include <cstdio>

// 三元组定义
typedef struct {
    int row;    // 行索引
    int col;    // 列索引
    int elem;   // 元素值
} Triple;

// 矩阵定义
typedef struct {
    int row = 0;    // 行数
    int col = 0;    // 列数
    std::vector<Triple> data;  // 元素数组
} Matrix;

//存储矩阵的函数
// 在 function level 上添加注释
// 将矩阵数据存储到自定义的 Matrix 结构中
void storeMatrix(Matrix &mat, int row, int col, std::vector<std::vector<int>> data) {
    mat.row = row;  // 存储矩阵行数
    mat.col = col;  // 存储矩阵列数
    for (int i = 0; i < row; i++) {  // 遍历矩阵行
        for (int j = 0; j < col; j++) {  // 遍历矩阵列
            Triple t;  // 创建 Triple 结构来存储矩阵数据
            t.row = i;  // 存储元素所在行
            t.col = j;  // 存储元素所在列
            t.elem = data[i][j];  // 存储元素值
            mat.data.push_back(t);  // 将 Triple 结构存入自定义 Matrix 结构中
        }
    }
}

//打印矩阵的函数
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.row; i++) {
        for (int j = 0; j < mat.col; j++) {
            Triple t = mat.data[i * mat.col + j];
            printf("%d ", t.elem);
        }
        printf("\n");
    }
}

// 打印非零元素的三元组
void printNonZero(Matrix mat) {
    for (int i = 0; i < mat.row; i++) {
        for (int j = 0; j < mat.col; j++) {
            Triple t = mat.data[i * mat.col + j];
            if (t.elem != 0) {
                printf("(%d, %d, %d)\n", t.row, t.col, t.elem);
            }
        }
    }
}

// 修改矩阵的元素
void modifyMatrix(Matrix &mat, int row, int col, int elem) {
    //丛非零元素中寻找要修改的元素
    for (auto & i : mat.data) {
        if (i.row == row && i.col == col) {
            i.elem = elem;
            return;
        }
    }
    //如果要修改的元素不存在，则添加一个新的元素
    Triple t;
    t.row = row;
    t.col = col;
    t.elem = elem;
    mat.data.push_back(t);
}

int main() {
    //一个8*8的稀疏矩阵
    std::vector<std::vector<int>> data1 = {
            {0, 3, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 7, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 6, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}
    };

    Matrix mat1;
    storeMatrix(mat1, 8, 8, data1);
    printf("矩阵1:\n");
    printMatrix(mat1);
    printf("非零元素的三元组:\n");
    printNonZero(mat1);
    modifyMatrix(mat1, 5, 4, 9);
    printf("修改后的矩阵1:\n");
    printMatrix(mat1);
    printf("非零元素的三元组:\n");
    printNonZero(mat1);



    return 0;
}