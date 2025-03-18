#include "SplashScene.h"
#include "MenuScene.h"  // Para cambiar a la siguiente escena
#include "../core/SceneManager.h"
#include <iostream>  // Para debug (opcional)

// Constructor: Define el tiempo de duración del splash screen
SplashScene::SplashScene() : elapsedTime(0.0f), displayDuration(3.0f) {}  // Se muestra 3 segundos

void SplashScene::init() {
    std::cout << "SplashScene iniciada" << std::endl;
    // Aquí podrías cargar una imagen o inicializar algún recurso gráfico
}

void SplashScene::handleInput() {
    // Si el usuario presiona una tecla o hace clic, se salta la pantalla inicial
    // Esta función se implementará según el sistema de entrada del motor gráfico
}

void SplashScene::update(float deltaTime) {
    elapsedTime += deltaTime;

    // Si pasa el tiempo especificado, cambia a MenuScene
    if (elapsedTime >= displayDuration) {
        SceneManager::getInstance().changeScene(std::make_shared<MenuScene>());
    }
}

void SplashScene::render() {
    // Aquí se dibujaría la imagen del splash screen
    std::cout << "Renderizando SplashScreen..." << std::endl;
}

void SplashScene::cleanup() {
    std::cout << "Liberando recursos de SplashScene" << std::endl;
    // Aquí se liberarían los recursos gráficos cargados
}
