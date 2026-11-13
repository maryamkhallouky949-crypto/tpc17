#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename T, int N, int M>
class Matrix {
private:
    T data[N][M];

public:
    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = T();
            }
        }
    }

    Matrix(std::initializer_list<std::initializer_list<T>> valeurs) {
        if (valeurs.size() != N) {
            throw std::invalid_argument("Nombre de lignes incorrect");
        }

        int i = 0;

        for (const auto& ligne : valeurs) {
            if (ligne.size() != M) {
                throw std::invalid_argument("Nombre de colonnes incorrect");
            }

            int j = 0;

            for (const auto& valeur : ligne) {
                data[i][j] = valeur;
                j++;
            }

            i++;
        }
    }

    T& at(int i, int j) {
        if (i < 0 || i >= N || j < 0 || j >= M) {
            throw std::out_of_range("Indice invalide");
        }

        return data[i][j];
    }

    const T& at(int i, int j) const {
        if (i < 0 || i >= N || j < 0 || j >= M) {
            throw std::out_of_range("Indice invalide");
        }

        return data[i][j];
    }

    Matrix<T, N, M> operator+(const Matrix<T, N, M>& autre) const {
        Matrix<T, N, M> resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                resultat.data[i][j] =
                    data[i][j] + autre.data[i][j];
            }
        }

        return resultat;
    }

    template <int P>
    Matrix<T, N, P> operator*(const Matrix<T, M, P>& autre) const {
        Matrix<T, N, P> resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                for (int k = 0; k < M; k++) {
                    resultat.at(i, j) +=
                        data[i][k] * autre.at(k, j);
                }
            }
        }

        return resultat;
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const Matrix<T, N, M>& matrice) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                os << matrice.data[i][j] << "\t";
            }

            os << '\n';
        }

        return os;
    }
};

#endif