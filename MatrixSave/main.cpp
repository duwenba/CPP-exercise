

#include <vector>
#include <cstdio>

// ��Ԫ�鶨��
typedef struct {
    int row;    // ������
    int col;    // ������
    int elem;   // Ԫ��ֵ
} Triple;

// ������
typedef struct {
    int row = 0;    // ����
    int col = 0;    // ����
    std::vector<Triple> data;  // Ԫ������
} Matrix;

//�洢����ĺ���
// �� function level �����ע��
// ���������ݴ洢���Զ���� Matrix �ṹ��
void storeMatrix(Matrix &mat, int row, int col, std::vector<std::vector<int>> data) {
    mat.row = row;  // �洢��������
    mat.col = col;  // �洢��������
    for (int i = 0; i < row; i++) {  // ����������
        for (int j = 0; j < col; j++) {  // ����������
            Triple t;  // ���� Triple �ṹ���洢��������
            t.row = i;  // �洢Ԫ��������
            t.col = j;  // �洢Ԫ��������
            t.elem = data[i][j];  // �洢Ԫ��ֵ
            mat.data.push_back(t);  // �� Triple �ṹ�����Զ��� Matrix �ṹ��
        }
    }
}

//��ӡ����ĺ���
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.row; i++) {
        for (int j = 0; j < mat.col; j++) {
            Triple t = mat.data[i * mat.col + j];
            printf("%d ", t.elem);
        }
        printf("\n");
    }
}

// ��ӡ����Ԫ�ص���Ԫ��
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

// �޸ľ����Ԫ��
void modifyMatrix(Matrix &mat, int row, int col, int elem) {
    //�Է���Ԫ����Ѱ��Ҫ�޸ĵ�Ԫ��
    for (auto & i : mat.data) {
        if (i.row == row && i.col == col) {
            i.elem = elem;
            return;
        }
    }
    //���Ҫ�޸ĵ�Ԫ�ز����ڣ������һ���µ�Ԫ��
    Triple t;
    t.row = row;
    t.col = col;
    t.elem = elem;
    mat.data.push_back(t);
}

int main() {
    //һ��8*8��ϡ�����
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
    printf("����1:\n");
    printMatrix(mat1);
    printf("����Ԫ�ص���Ԫ��:\n");
    printNonZero(mat1);
    modifyMatrix(mat1, 5, 4, 9);
    printf("�޸ĺ�ľ���1:\n");
    printMatrix(mat1);
    printf("����Ԫ�ص���Ԫ��:\n");
    printNonZero(mat1);



    return 0;
}