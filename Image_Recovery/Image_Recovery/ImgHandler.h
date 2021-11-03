
/**
 * @file ImgHandler.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Clase de Image Handler
 * @brief Esta clase se encarga de recortar la imagen de referencia la cual se usa para evaluar el fitness de los 
 * individuos, ademas se encarga de colocar y dibujar las poblaciones en pantalla y de eliminar los pixeles que el usuario indique
 * @date 11/3/2021
 */
#pragma once
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
class ImgHandler
{
public:
    /**
 * @brief Metodo el cual se encarga recortar una imagen de referencia.
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @param m matriz de OpenCV
 * @param x Posicion en x
 * @param y Posicion en Y
 * @param width El ancho de la imagen 
 * @param heigth La altura de la imagen
 */
	Mat cut_ref(Mat m, int x, int y, int width, int heigth);

	/**
* @brief Metodo el cual se encarga de colocar las imagenes resultantes del algoritmo genetico
* @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
* @param x Posicion en x
 * @param y Posicion en Y
 * @param m1 matriz numero 1 de OpenCV 
 * @param m2 matriz numero 2 de OpenCV
*/
	Mat place(Mat m1, Mat m2,int x, int y);

	/**
* @brief Metodo el cual se encarga de eliminar los pixeles de la imagen original.
* @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
*  @param x Posicion en x
 * @param y Posicion en Y
 * @param w El ancho de la imagen 
 * @param h La altura de la imagen
*/
	Mat erase(Mat m, int w, int h, int x, int y); 
};

