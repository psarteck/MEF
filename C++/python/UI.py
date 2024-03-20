import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QPushButton
from PyQt5.QtCore import QProcess

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Appel de fonction C++ avec Qt en Python")
        self.setGeometry(100, 100, 400, 200)

        # Créer un bouton pour lancer le calcul
        self.button = QPushButton("Lancer le calcul")
        self.button.clicked.connect(self.run_cpp_function)

        # Ajouter le bouton au layout vertical
        layout = QVBoxLayout()
        layout.addWidget(self.button)

        # Créer un widget conteneur pour le layout
        widget = QWidget()
        widget.setLayout(layout)

        # Définir le widget conteneur comme widget central de la fenêtre principale
        self.setCentralWidget(widget)

    def run_cpp_function(self):
        # Appeler la fonction calculate() directement
        calculate()

def calculate():
    # Code de la fonction calculate() en C++
    # Ouvrir le fichier "data.txt" en mode écriture
    with open("data.txt", "w") as file:
        # Écrire les premiers entiers de 1 à 15 dans le fichier
        for i in range(1, 16):
            file.write(str(i) + "\n")
    print("Les premiers entiers de 1 à 15 ont été écrits dans le fichier data.txt")

if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = MainWindow()
    mainWindow.show()
    sys.exit(app.exec_())
