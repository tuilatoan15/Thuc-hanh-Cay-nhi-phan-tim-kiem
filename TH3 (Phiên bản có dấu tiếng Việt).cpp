#include <iostream>
#include <cmath>

using namespace std;

// Cấu trúc Node cho cây nhị phân tìm kiếm
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Phần 2: Cây nhị phân tìm kiếm

// 1. Khai báo cấu trúc dữ liệu cây nhị phân
// Đã được khai báo trong struct Node

// 2. Khởi tạo cây rỗng
Node* root = nullptr;

// 3. Tạo 1 node có key bằng x
Node* createNode(int x) {
    return new Node(x);
}

// 4. Chèn node x vào cây
Node* insertNode(Node* root, int x) {
    if (root == nullptr) {
        return createNode(x);
    }

    if (x < root->key) {
        root->left = insertNode(root->left, x);
    } else if (x > root->key) {
        root->right = insertNode(root->right, x);
    }

    return root;
}

// 5. Tạo cây
void createTree(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
}

// 6. Tìm node có khóa bằng x: dùng đệ quy
Node* searchRecursive(Node* root, int x) {
    if (root == nullptr || root->key == x) {
        return root;
    }

    if (x < root->key) {
        return searchRecursive(root->left, x);
    }

    return searchRecursive(root->right, x);
}

// 7. Tìm node có khóa bằng x: không dùng đệ quy
Node* searchIterative(Node* root, int x) {
    while (root != nullptr && root->key != x) {
        if (x < root->key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}

// 8. Xóa 1 node có khóa x
Node* deleteNode(Node* root, int x) {
    if (root == nullptr) {
        return root;
    }

    if (x < root->key) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->key) {
        root->right = deleteNode(root->right, x);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// 9. Tìm phần tử lớn nhất
Node* findMax(Node* root) {
    while (root != nullptr && root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// 10. Tìm phần tử nhỏ nhất
Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// 11. Chiều cao cây: mức lớn nhất trên cây
int treeHeight(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// 12. Tính tổng các node có giá trị âm trong cây
int sumNegativeNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = sumNegativeNodes(root->left);
    int rightSum = sumNegativeNodes(root->right);

    return (root->key < 0 ? root->key : 0) + leftSum + rightSum;
}

// 13. Tính tích các node có giá trị dương trong cây
int productPositiveNodes(Node* root) {
    if (root == nullptr) {
        return 1;
    }

    int leftProduct = productPositiveNodes(root->left);
    int rightProduct = productPositiveNodes(root->right);

    return (root->key > 0 ? root->key : 1) * leftProduct * rightProduct;
}

// 14. Hàm kiểm tra trong cây có tồn tại giá trị 0 hay không?
bool containsZero(Node* root) {
    if (root == nullptr) {
        return false;
    }

    if (root->key == 0) {
        return true;
    }

    return containsZero(root->left) || containsZero(root->right);
}

// 15. Duyệt trước: Pre-order
void preOrderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// 16. Duyệt giữa: In-order
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

// 17. Duyệt sau: Post-order
void postOrderTraversal(Node* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->key << " ";
    }
}

// 18. In ra các node có giá trị nhỏ hơn x
void printNodesLessThanX(Node* root, int x) {
    if (root != nullptr) {
        printNodesLessThanX(root->left, x);
        if (root->key < x) {
            cout << root->key << " ";
        }
        printNodesLessThanX(root->right, x);
    }
}

// 19. Xuất giá trị các nút trên cây có giá trị (khóa) lớn hơn x và nhỏ hơn y
void printNodesInRange(Node* root, int x, int y) {
    if (root != nullptr) {
        printNodesInRange(root->left, x, y);
        if (root->key >= x && root->key <= y) {
            cout << root->key << " ";
        }
        printNodesInRange(root->right, x, y);
    }
}

// 20. Xuất các số hoàn hiện trong cây
bool isPerfectNumber(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}

void printPerfectNumbers(Node* root) {
    if (root != nullptr) {
        printPerfectNumbers(root->left);
        if (isPerfectNumber(root->key)) {
            cout << root->key << " ";
        }
        printPerfectNumbers(root->right);
    }
}

// 21. Tính mức (level) của 1 node
int getNodeLevel(Node* root, int key, int level = 0) {
    if (root == nullptr) {
        return -1; // Không tìm thấy node
    }

    if (root->key == key) {
        return level;
    }

    int leftLevel = getNodeLevel(root->left, key, level + 1);
    if (leftLevel != -1) {
        return leftLevel;
    }

    return getNodeLevel(root->right, key, level + 1);
}

// 22. Xuất tất cả các nút trên tầng thứ k của cây
void printNodesAtLevel(Node* root, int k) {
    if (root == nullptr) {
        return;
    }

    if (k == 0) {
        cout << root->key << " ";
    } else {
        printNodesAtLevel(root->left, k - 1);
        printNodesAtLevel(root->right, k - 1);
    }
}

// 23. Xuất tất cả các nút trên cây theo thứ tự từ tầng 0 đến tầng h – 1 của cây (với h là chiều cao của cây)
void printAllLevels(Node* root) {
    int height = treeHeight(root);
    for (int i = 0; i <= height; i++) {
        printNodesAtLevel(root, i);
        cout << endl;
    }
}

// 24. Đếm số lượng nút có đúng một con
int countNodesWithOneChild(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNodesWithOneChild(root->left);
    int rightCount = countNodesWithOneChild(root->right);

    if ((root->left == nullptr && root->right != nullptr) ||
        (root->left != nullptr && root->right == nullptr)) {
        return 1 + leftCount + rightCount;
    }

    return leftCount + rightCount;
}

// 25. Đếm số lượng nút có đúng hai con
int countNodesWithTwoChildren(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNodesWithTwoChildren(root->left);
    int rightCount = countNodesWithTwoChildren(root->right);

    if (root->left != nullptr && root->right != nullptr) {
        return 1 + leftCount + rightCount;
    }

    return leftCount + rightCount;
}

// 26. Đếm số lượng nút chẵn
int countEvenNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countEvenNodes(root->left);
    int rightCount = countEvenNodes(root->right);

    return (root->key % 2 == 0 ? 1 : 0) + leftCount + rightCount;
}

// 27. Đếm số lượng nút lá mà thông tin tại nút đó là giá trị chẵn
int countLeafNodesWithEvenValue(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return (root->key % 2 == 0 ? 1 : 0);
    }

    return countLeafNodesWithEvenValue(root->left) + countLeafNodesWithEvenValue(root->right);
}

// 28. Đếm số lượng nút có đúng một con mà thông tin tại nút đó là số nguyên tố
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countNodesWithOneChildAndPrimeValue(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNodesWithOneChildAndPrimeValue(root->left);
    int rightCount = countNodesWithOneChildAndPrimeValue(root->right);

    if ((root->left == nullptr && root->right != nullptr) ||
        (root->left != nullptr && root->right == nullptr)) {
        return (isPrime(root->key) ? 1 : 0) + leftCount + rightCount;
    }

    return leftCount + rightCount;
}

// 29. Đếm số lượng nút có đúng hai con mà thông tin tại nút đó là số chính phương
bool isPerfectSquare(int num) {
    int squareRoot = static_cast<int>(sqrt(num));
    return squareRoot * squareRoot == num;
}

int countNodesWithTwoChildrenAndPerfectSquareValue(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNodesWithTwoChildrenAndPerfectSquareValue(root->left);
    int rightCount = countNodesWithTwoChildrenAndPerfectSquareValue(root->right);

    if (root->left != nullptr && root->right != nullptr) {
        return (isPerfectSquare(root->key) ? 1 : 0) + leftCount + rightCount;
    }

    return leftCount + rightCount;
}

// 30. Đếm số node
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 31. Đếm số node lá
int countLeafNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// 32. Đếm số node nhánh
int countBranchNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left != nullptr || root->right != nullptr) {
        return 1 + countBranchNodes(root->left) + countBranchNodes(root->right);
    }

    return 0;
}

// 33. Đếm các node có giá trị âm có trong cây
int countNegativeNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNegativeNodes(root->left);
    int rightCount = countNegativeNodes(root->right);

    return (root->key < 0 ? 1 : 0) + leftCount + rightCount;
}

// 34. Đếm số lượng nút trên tầng thứ k của cây.
int countNodesAtLevelK(Node* root, int k) {
    if (root == nullptr) {
        return 0;
    }

    if (k == 0) {
        return 1;
    }

    return countNodesAtLevelK(root->left, k - 1) + countNodesAtLevelK(root->right, k - 1);
}

// 35. Đếm số lượng nút nằm ở tầng thấp hơn tầng thứ k của cây.
int countNodesBelowLevelK(Node* root, int k) {
    if (root == nullptr || k <= 0) {
        return 0;
    }

    return countNodesAtLevelK(root->left, k - 1) + countNodesAtLevelK(root->right, k - 1);
}

// 36. Đếm số lượng nút nằm ở tầng cao hơn tầng thứ k của cây.
int countNodesAboveLevelK(Node* root, int k) {
    int height = treeHeight(root);
    if (k >= height) {
        return 0;
    }

    return countNodesAtLevelK(root, height) - countNodesAtLevelK(root, k);
}

// 37. Đếm số nút có khóa lớn hơn x
int countNodesGreaterThanX(Node* root, int x) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNodesGreaterThanX(root->left, x);
    int rightCount = countNodesGreaterThanX(root->right, x);

    return (root->key > x ? 1 : 0) + leftCount + rightCount;
}

// 38. Xóa toàn bộ cây
void deleteTree(Node*& root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
    root = nullptr;
}

int main() {
    int arr[] = {5, 3, 8, 2, 4, 7, 9, 5, 6, 7, 4, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 2. Khởi tạo cây rỗng
    // (Không cần thực hiện bước này vì cây đã được tạo từ dãy số)

    // 3. Tạo 1 node có key bằng x
    int xToCreate = 6;
    Node* newNode = new Node(xToCreate);

    // 4. Chèn node x vào cây
    root = insertNode(root, xToCreate);

    // 5. Tạo cây
    createTree(arr, n);

    // 6. Tìm node có khóa bằng x: dùng đệ quy
    int xRecursive = 4;
    Node* foundNodeRecursive = searchRecursive(root, xRecursive);
    if (foundNodeRecursive != nullptr) {
        cout << "Nút có khóa " << xRecursive << " được tìm thấy (đệ quy)." << endl;
    } else {
        cout << "Nút có khóa " << xRecursive << " không được tìm thấy (đệ quy)." << endl;
    }

    // 7. Tìm node có khóa bằng x: không dùng đệ quy
    int xIterative = 7;
    Node* foundNodeIterative = searchIterative(root, xIterative);
    if (foundNodeIterative != nullptr) {
        cout << "Nút có khóa " << xIterative << " được tìm thấy (không đệ quy)." << endl;
    } else {
        cout << "Nút có khóa " << xIterative << " không được tìm thấy (không đệ quy)." << endl;
    }

    // 8. Xóa 1 node có khóa x
    int keyToDelete = 3;
    root = deleteNode(root, keyToDelete);
    cout << "Nút có khóa " << keyToDelete << " đã được xóa." << endl;

    // 9. Tìm phần tử lớn nhất
    Node* maxNode = findMax(root);
    cout << "Phần tử lớn nhất trong cây: " << maxNode->key << endl;

    // 10. Tìm phần tử nhỏ nhất
    Node* minNode = findMin(root);
    cout << "Phần tử nhỏ nhất trong cây: " << minNode->key << endl;

    // 11. Chiều cao cây: mức lớn nhất trên cây
    int height = treeHeight(root);
    cout << "Chiều cao của cây: " << height << endl;

    // 12. Tính tổng các node có giá trị âm trong cây
    int sumNegatives = sumNegativeNodes(root);
    cout << "Tổng các node có giá trị âm trong cây: " << sumNegatives << endl;

    // 13. Tính tích các node có giá trị dương trong cây
    int productPositives = productPositiveNodes(root);
    cout << "Tích các node có giá trị dương trong cây: " << productPositives << endl;

    // 14. Hàm kiểm tra trong cây có tồn tại giá trị 0 hay không?
    bool hasZero = containsZero(root);
    cout << "Cây " << (hasZero ? "chứa" : "không chứa") << " giá trị 0." << endl;

    // 15. Duyệt trước: Pre-order
    cout << "Duyệt trước: ";
    preOrderTraversal(root);
    cout << endl;

    // 16. Duyệt giữa: In-order
    cout << "Duyệt giữa: ";
    inOrderTraversal(root);
    cout << endl;

    // 17. Duyệt sau: Post-order
    cout << "Duyệt sau: ";
    postOrderTraversal(root);
    cout << endl;

    // 18. In ra các node có giá trị nhỏ hơn x
    int threshold = 6;
    cout << "Các node có giá trị nhỏ hơn " << threshold << ": ";
    printNodesLessThanX(root, threshold);
    cout << endl;

    // 19. Xuất giá trị các nút trên cây có giá trị (khóa) lớn hơn x và nhỏ hơn y
    int xRange = 3, yRange = 8;
    cout << "Các node trong khoảng [" << xRange << ", " << yRange << "]: ";
    printNodesInRange(root, xRange, yRange);
    cout << endl;

    // 20. Xuất các số hoàn hiện trong cây
    cout << "Các số hoàn hiện trong cây: ";
    printPerfectNumbers(root);
    cout << endl;

    // 21. Tính mức (level) của 1 node
    int nodeLevel = getNodeLevel(root, 5);
    cout << "Mức của nút có khóa 5: " << nodeLevel << endl;

    // 22. Viết hàm xuất tất cả các nút trên tầng thứ k của cây
    int kLevel = 2;
    cout << "Các nút ở tầng " << kLevel << ": ";
    printNodesAtLevel(root, kLevel);
    cout << endl;

    // 23. Viết hàm xuất tất cả các nút trên cây theo thứ tự từ tầng 0 đến tầng h – 1 của cây
    cout << "Tất cả các tầng của cây: " << endl;
    printAllLevels(root);

    // 24. Đếm số lượng nút có đúng một con
    int countOneChildNodes = countNodesWithOneChild(root);
    cout << "Số lượng nút có một con: " << countOneChildNodes << endl;

    // 25. Đếm số lượng nút có đúng hai con
    int countTwoChildrenNodes = countNodesWithTwoChildren(root);
    cout << "Số lượng nút có hai con: " << countTwoChildrenNodes << endl;

    // 26. Đếm số lượng nút chẵn
    int countEvenNodesResult = countEvenNodes(root);
    cout << "Số lượng nút chẵn: " << countEvenNodesResult << endl;

    // 27. Đếm số lượng nút lá mà thông tin tại nút đó là giá trị chẵn
    int countLeafEvenNodes = countLeafNodesWithEvenValue(root);
    cout << "Số lượng nút lá có giá trị chẵn: " << countLeafEvenNodes << endl;

    // 28. Đếm số lượng nút có đúng một con mà thông tin tại nút đó là số nguyên tố
    int countOneChildPrimeNodes = countNodesWithOneChildAndPrimeValue(root);
    cout << "Số lượng nút có một con và giá trị là số nguyên tố: " << countOneChildPrimeNodes << endl;

    // 29. Đếm số lượng nút có đúng hai con mà thông tin tại nút đó là số chính phương
    int countTwoChildrenPerfectSquareNodes = countNodesWithTwoChildrenAndPerfectSquareValue(root);
    cout << "Số lượng nút có hai con và giá trị là số chính phương: " << countTwoChildrenPerfectSquareNodes << endl;

    // 30. Đếm số node
    int countAllNodes = countNodes(root);
    cout << "Số lượng nút trong cây: " << countAllNodes << endl;

    // 31. Đếm số node lá
    int countLeafNodesResult = countLeafNodes(root);
    cout << "Số lượng nút lá trong cây: " << countLeafNodesResult << endl;

    // 32. Đếm số node nhánh
    int countBranchNodesResult = countBranchNodes(root);
    cout << "Số lượng nút nhánh trong cây: " << countBranchNodesResult << endl;

    // 33. Đếm các node có giá trị âm có trong cây
    int countNegativeNodesResult = countNegativeNodes(root);
    cout << "Số lượng nút có giá trị âm trong cây: " << countNegativeNodesResult << endl;

    // 34. Đếm số lượng nút trên tầng thứ k của cây.
    int kLevelCount = countNodesAtLevelK(root, kLevel);
    cout << "Số lượng nút ở tầng " << kLevel << ": " << kLevelCount << endl;

    // 35. Đếm số lượng nút nằm ở tầng thấp hơn tầng thứ k của cây.
    int belowLevelKCount = countNodesBelowLevelK(root, kLevel);
    cout << "Số lượng nút nằm dưới tầng " << kLevel << ": " << belowLevelKCount << endl;

    // 36. Đếm số lượng nút nằm ở tầng cao hơn tầng thứ k của cây.
    int aboveLevelKCount = countNodesAboveLevelK(root, kLevel);
    cout << "Số lượng nút nằm trên tầng " << kLevel << ": " << aboveLevelKCount << endl;

    // 37. Đếm số nút có khóa lớn hơn x
    int xToCompare = 5;
    int nodesGreaterThanXCount = countNodesGreaterThanX(root, xToCompare);
    cout << "Số lượng nút có khóa lớn hơn " << xToCompare << ": " << nodesGreaterThanXCount << endl;

    // 38. Xóa toàn bộ cây
    deleteTree(root);
    cout << "Cây đã bị xóa." << endl;

    return 0;
}