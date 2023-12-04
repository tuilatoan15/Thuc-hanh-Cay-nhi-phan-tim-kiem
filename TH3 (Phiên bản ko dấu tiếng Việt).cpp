#include <iostream>
#include <cmath>

using namespace std;

// Cau truc Node cho cay nhi phan tim kiem
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Phan 2: Cay nhi phan tim kiem

// 1. Khai bao cau truc du lieu cay nhi phan
// Da duoc khai bao trong struct Node

// 2. Khoi tao cay rong
Node* root = nullptr;

// 3. Tao 1 node co key bang x
Node* createNode(int x) {
    return new Node(x);
}

// 4. Chen node x vao cay
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

// 5. Tao cay
void createTree(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
}

// 6. Tim node co khoa bang x: dung de quy
Node* searchRecursive(Node* root, int x) {
    if (root == nullptr || root->key == x) {
        return root;
    }

    if (x < root->key) {
        return searchRecursive(root->left, x);
    }

    return searchRecursive(root->right, x);
}

// 7. Tim node co khoa bang x: khong dung de quy
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

// 8. Xoa 1 node co khoa x
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

// 9. Tim phan tu lon nhat
Node* findMax(Node* root) {
    while (root != nullptr && root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// 10. Tim phan tu nho nhat
Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// 11. Chieu cao cay: muc lon nhat tren cay
int treeHeight(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// 12. Tinh tong cac node co gia tri am trong cay
int sumNegativeNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = sumNegativeNodes(root->left);
    int rightSum = sumNegativeNodes(root->right);

    return (root->key < 0 ? root->key : 0) + leftSum + rightSum;
}

// 13. Tinh tich cac node co gia tri duong trong cay
int productPositiveNodes(Node* root) {
    if (root == nullptr) {
        return 1;
    }

    int leftProduct = productPositiveNodes(root->left);
    int rightProduct = productPositiveNodes(root->right);

    return (root->key > 0 ? root->key : 1) * leftProduct * rightProduct;
}

// 14. Ham kiem tra trong cay co ton tai gia tri 0 hay khong?
bool containsZero(Node* root) {
    if (root == nullptr) {
        return false;
    }

    if (root->key == 0) {
        return true;
    }

    return containsZero(root->left) || containsZero(root->right);
}

// 15. Duyet truoc: Pre-order
void preOrderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// 16. Duyet giua: In-order
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

// 17. Duyet sau: Post-order
void postOrderTraversal(Node* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->key << " ";
    }
}

// 18. In ra cac node co gia tri nho hon x
void printNodesLessThanX(Node* root, int x) {
    if (root != nullptr) {
        printNodesLessThanX(root->left, x);
        if (root->key < x) {
            cout << root->key << " ";
        }
        printNodesLessThanX(root->right, x);
    }
}

// 19. Xuat gia tri cac nut tren cay co gia tri (khoa) lon hon x va nho hon y
void printNodesInRange(Node* root, int x, int y) {
    if (root != nullptr) {
        printNodesInRange(root->left, x, y);
        if (root->key >= x && root->key <= y) {
            cout << root->key << " ";
        }
        printNodesInRange(root->right, x, y);
    }
}

// 20. Xuat cac so hoan hien trong cay
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

// 21. Tinh muc (level) cua 1 node
int getNodeLevel(Node* root, int key, int level = 0) {
    if (root == nullptr) {
        return -1; // Khong tim thay node
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

// 22. Xuat tat ca cac nut tren tang thu k cua cay
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

// 23. Xuat tat ca cac nut tren cay theo thu tu tu tang 0 den tang h – 1 cua cay (voi h la chieu cao cua cay)
void printAllLevels(Node* root) {
    int height = treeHeight(root);
    for (int i = 0; i <= height; i++) {
        printNodesAtLevel(root, i);
        cout << endl;
    }
}

// 24. Dem so luong nut co dung mot con
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

// 25. Dem so luong nut co dung hai con
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

// 26. Dem so luong nut chan
int countEvenNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countEvenNodes(root->left);
    int rightCount = countEvenNodes(root->right);

    return (root->key % 2 == 0 ? 1 : 0) + leftCount + rightCount;
}

// 27. Dem so luong nut la ma thong tin tai nut do la gia tri chan
int countLeafNodesWithEvenValue(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return (root->key % 2 == 0 ? 1 : 0);
    }

    return countLeafNodesWithEvenValue(root->left) + countLeafNodesWithEvenValue(root->right);
}

// 28. Dem so luong nut co dung mot con ma thong tin tai nut do la so nguyen to
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

// 29. Dem so luong nut co dung hai con ma thong tin tai nut do la so chinh phuong
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

// 30. Dem so node
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 31. Dem so node la
int countLeafNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// 32. Dem so node nhanh
int countBranchNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left != nullptr || root->right != nullptr) {
        return 1 + countBranchNodes(root->left) + countBranchNodes(root->right);
    }

    return 0;
}

// 33. Dem cac node co gia tri am co trong cay
int countNegativeNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNegativeNodes(root->left);
    int rightCount = countNegativeNodes(root->right);

    return (root->key < 0 ? 1 : 0) + leftCount + rightCount;
}

// 34. Dem so luong nut tren tang thu k cua cay.
int countNodesAtLevelK(Node* root, int k) {
    if (root == nullptr) {
        return 0;
    }

    if (k == 0) {
        return 1;
    }

    return countNodesAtLevelK(root->left, k - 1) + countNodesAtLevelK(root->right, k - 1);
}

// 35. Dem so luong nut nam o tang thap hon tang thu k cua cay.
int countNodesBelowLevelK(Node* root, int k) {
    if (root == nullptr || k <= 0) {
        return 0;
    }

    return countNodesAtLevelK(root->left, k - 1) + countNodesAtLevelK(root->right, k - 1);
}

// 36. Dem so luong nut nam o tang cao hon tang thu k cua cay.
int countNodesAboveLevelK(Node* root, int k) {
    int height = treeHeight(root);
    if (k >= height) {
        return 0;
    }

    return countNodesAtLevelK(root, height) - countNodesAtLevelK(root, k);
}

// 37. Dem so nut co khoa lon hon x
int countNodesGreaterThanX(Node* root, int x) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNodesGreaterThanX(root->left, x);
    int rightCount = countNodesGreaterThanX(root->right, x);

    return (root->key > x ? 1 : 0) + leftCount + rightCount;
}

// 38. Xoa toan bo cay
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

    // 2. Khoi tao cay rong
    // (Khong can thuc hien buoc nay vi cay da duoc tao tu day so)

    // 3. Tao 1 node co key bang x
    int xToCreate = 6;
    Node* newNode = new Node(xToCreate);

    // 4. Chen node x vao cay
    root = insertNode(root, xToCreate);

    // 5. Tao cay
    createTree(arr, n);

    // 6. Tim node co khoa bang x: dung de quy
    int xRecursive = 4;
    Node* foundNodeRecursive = searchRecursive(root, xRecursive);
    if (foundNodeRecursive != nullptr) {
        cout << "Nut co khoa " << xRecursive << " duoc tim thay (de quy)." << endl;
    } else {
        cout << "Nut co khoa " << xRecursive << " khong duoc tim thay (de quy)." << endl;
    }

    // 7. Tim node co khoa bang x: khong dung de quy
    int xIterative = 7;
    Node* foundNodeIterative = searchIterative(root, xIterative);
    if (foundNodeIterative != nullptr) {
        cout << "Nut co khoa " << xIterative << " duoc tim thay (khong de quy)." << endl;
    } else {
        cout << "Nut co khoa " << xIterative << " khong duoc tim thay (khong de quy)." << endl;
    }

    // 8. Xoa 1 node co khoa x
    int keyToDelete = 3;
    root = deleteNode(root, keyToDelete);
    cout << "Nut co khoa " << keyToDelete << " da duoc xoa." << endl;

    // 9. Tim phan tu lon nhat
    Node* maxNode = findMax(root);
    cout << "Phan tu lon nhat trong cay: " << maxNode->key << endl;

    // 10. Tim phan tu nho nhat
    Node* minNode = findMin(root);
    cout << "Phan tu nho nhat trong cay: " << minNode->key << endl;

    // 11. Chieu cao cay: muc lon nhat tren cay
    int height = treeHeight(root);
    cout << "Chieu cao cua cay: " << height << endl;

    // 12. Tinh tong cac node co gia tri am trong cay
    int sumNegatives = sumNegativeNodes(root);
    cout << "Tong cac node co gia tri am trong cay: " << sumNegatives << endl;

    // 13. Tinh tich cac node co gia tri duong trong cay
    int productPositives = productPositiveNodes(root);
    cout << "Tich cac node co gia tri duong trong cay: " << productPositives << endl;

    // 14. Ham kiem tra trong cay co ton tai gia tri 0 hay khong?
    bool hasZero = containsZero(root);
    cout << "Cay " << (hasZero ? "chua" : "khong chua") << " gia tri 0." << endl;

    // 15. Duyet truoc: Pre-order
    cout << "Duyet truoc: ";
    preOrderTraversal(root);
    cout << endl;

    // 16. Duyet giua: In-order
    cout << "Duyet giua: ";
    inOrderTraversal(root);
    cout << endl;

    // 17. Duyet sau: Post-order
    cout << "Duyet sau: ";
    postOrderTraversal(root);
    cout << endl;

    // 18. In ra cac node co gia tri nho hon x
    int threshold = 6;
    cout << "Cac node co gia tri nho hon " << threshold << ": ";
    printNodesLessThanX(root, threshold);
    cout << endl;

    // 19. Xuat gia tri cac nut tren cay co gia tri (khoa) lon hon x va nho hon y
    int xRange = 3, yRange = 8;
    cout << "Cac node trong khoang [" << xRange << ", " << yRange << "]: ";
    printNodesInRange(root, xRange, yRange);
    cout << endl;

    // 20. Xuat cac so hoan hien trong cay
    cout << "Cac so hoan hien trong cay: ";
    printPerfectNumbers(root);
    cout << endl;

    // 21. Tinh muc (level) cua 1 node
    int nodeLevel = getNodeLevel(root, 5);
    cout << "Muc cua nut co khoa 5: " << nodeLevel << endl;

    // 22. Viet ham xuat tat ca cac nut tren tang thu k cua cay
    int kLevel = 2;
    cout << "Cac nut o tang " << kLevel << ": ";
    printNodesAtLevel(root, kLevel);
    cout << endl;

    // 23. Viet ham xuat tat ca cac nut tren cay theo thu tu tu tang 0 den tang h – 1 cua cay
    cout << "Tat ca cac tang cua cay: " << endl;
    printAllLevels(root);

    // 24. Dem so luong nut co dung mot con
    int countOneChildNodes = countNodesWithOneChild(root);
    cout << "So luong nut co mot con: " << countOneChildNodes << endl;

    // 25. Dem so luong nut co dung hai con
    int countTwoChildrenNodes = countNodesWithTwoChildren(root);
    cout << "So luong nut co hai con: " << countTwoChildrenNodes << endl;

    // 26. Dem so luong nut chan
    int countEvenNodesResult = countEvenNodes(root);
    cout << "So luong nut chan: " << countEvenNodesResult << endl;

    // 27. Dem so luong nut la ma thong tin tai nut do la gia tri chan
    int countLeafEvenNodes = countLeafNodesWithEvenValue(root);
    cout << "So luong nut la co gia tri chan: " << countLeafEvenNodes << endl;

    // 28. Dem so luong nut co dung mot con ma thong tin tai nut do la so nguyen to
    int countOneChildPrimeNodes = countNodesWithOneChildAndPrimeValue(root);
    cout << "So luong nut co mot con va gia tri la so nguyen to: " << countOneChildPrimeNodes << endl;

    // 29. Dem so luong nut co dung hai con ma thong tin tai nut do la so chinh phuong
    int countTwoChildrenPerfectSquareNodes = countNodesWithTwoChildrenAndPerfectSquareValue(root);
    cout << "So luong nut co hai con va gia tri la so chinh phuong: " << countTwoChildrenPerfectSquareNodes << endl;

    // 30. Dem so node
    int countAllNodes = countNodes(root);
    cout << "So luong nut trong cay: " << countAllNodes << endl;

    // 31. Dem so node la
    int countLeafNodesResult = countLeafNodes(root);
    cout << "So luong nut la trong cay: " << countLeafNodesResult << endl;

    // 32. Dem so node nhanh
    int countBranchNodesResult = countBranchNodes(root);
    cout << "So luong nut nhanh trong cay: " << countBranchNodesResult << endl;

    // 33. Dem cac node co gia tri am co trong cay
    int countNegativeNodesResult = countNegativeNodes(root);
    cout << "So luong nut co gia tri am trong cay: " << countNegativeNodesResult << endl;

    // 34. Dem so luong nut tren tang thu k cua cay.
    int kLevelCount = countNodesAtLevelK(root, kLevel);
    cout << "So luong nut o tang " << kLevel << ": " << kLevelCount << endl;

    // 35. Dem so luong nut nam o tang thap hon tang thu k cua cay.
    int belowLevelKCount = countNodesBelowLevelK(root, kLevel);
    cout << "So luong nut nam duoi tang " << kLevel << ": " << belowLevelKCount << endl;

    // 36. Dem so luong nut nam o tang cao hon tang thu k cua cay.
    int aboveLevelKCount = countNodesAboveLevelK(root, kLevel);
    cout << "So luong nut nam tren tang " << kLevel << ": " << aboveLevelKCount << endl;

    // 37. Dem so nut co khoa lon hon x
    int xToCompare = 5;
    int nodesGreaterThanXCount = countNodesGreaterThanX(root, xToCompare);
    cout << "So luong nut co khoa lon hon " << xToCompare << ": " << nodesGreaterThanXCount << endl;

    // 38. Xoa toan bo cay
    deleteTree(root);
    cout << "Cay da bi xoa." << endl;

    return 0;
}