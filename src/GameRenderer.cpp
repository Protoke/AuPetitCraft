//
// Created by protoke on 25/02/17.
//

#include "GameRenderer.h"
#include "BlockRender.h"
#include "Block.h"
#include "WorldRender.h"

GameRenderer::GameRenderer() {
    memset(keys, 0, sizeof(keys));

    camera = Camera(glm::vec3(0.0f, 17.0f, 0.0f));

    /* Initialisation du contexte */
    GLFWwindow *window;
    if(initApp(window, WIDTH, HEIGHT) != 0){
        throw std::logic_error("Unable to init window.");
    }

    World world;

    Texture::configTextures();
    TextureManager textureManager;

    textureManager.loadTexture("../resources/textures/blocks/stone.png", STONE);

    BlockRender br(textureManager);
    WorldRender wr(&world, br);

    /* Def de trucs utiles pour la boucle */
    // Objets à afficher

//    glm::vec3 cubePositions[] = {
//            glm::vec3( 0.0f,  0.0f,  0.0f),
//            glm::vec3( 1.0f,  0.0f,  0.0f),
//            glm::vec3( 0.0f,  1.0f,  0.0f),
//            glm::vec3( 1.0f,  1.0f,  0.0f),
//            glm::vec3(-1.0f,  0.0f,  0.0f),
//            glm::vec3( 0.0f, -1.0f,  0.0f),
//            glm::vec3(-1.0f, -1.0f,  0.0f),
//            glm::vec3( 1.0f, -1.0f,  0.0f),
//            glm::vec3(-1.0f,  1.0f,  0.0f),
//            glm::vec3( 0.0f,  0.0f,  1.0f)
//    };

    // shaders
    Shader shaderProgram("/home/protoke/CLionProjects/TestOpenGL/shaders/vertex.vert", "/home/protoke/CLionProjects/TestOpenGL/shaders/fragment.frag");

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Pour dessiner que les arrêtes des triangles

    // Boucle principale
    while(!glfwWindowShouldClose(window))
    {
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Check des events
        glfwPollEvents();
        do_movement();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Définition le programme de shaders à utiliser
        shaderProgram.use();

        // Matrices de projection et de vue
        shaderProgram.setUniform("view", GameRenderer::camera.GetViewMatrix());
        shaderProgram.setUniform("projection", glm::perspective(glm::radians(camera.Zoom), (GLfloat)WIDTH/(GLfloat)HEIGHT, 0.1f, 100.0f));

        // Affichage de l'objet enregistré dans le VAO
        br.startDrawing();
        wr.drawWorld(shaderProgram);
        br.stopDrawing();

        // Affichage
        glfwSwapBuffers(window);
    }

    // Nettoyage
    glfwTerminate();
}

void GameRenderer::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    GameRenderer *this_ = (GameRenderer*)glfwGetWindowUserPointer(window);

    // When a user presses the escape key, we set the WindowShouldClose property to true,
    // closing the application
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if(action == GLFW_PRESS)
        this_->keys[key] = true;
    else if(action == GLFW_RELEASE)
        this_->keys[key] = false;
}

void GameRenderer::do_movement() {
    // Camera controls
    if(keys[GLFW_KEY_W])
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if(keys[GLFW_KEY_S])
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if(keys[GLFW_KEY_A])
        camera.ProcessKeyboard(LEFT, deltaTime);
    if(keys[GLFW_KEY_D])
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

void GameRenderer::mouse_callback(GLFWwindow* window, double xpos, double ypos){
    GameRenderer *this_ = (GameRenderer*)glfwGetWindowUserPointer(window);

    if(this_->firstMouse) // this bool variable is initially set to true
    {
        this_->lastX = xpos;
        this_->lastY = ypos;
        this_->firstMouse = false;
    }

    GLfloat xoffset = xpos - this_->lastX;
    GLfloat yoffset = this_->lastY - ypos; // Reversed since y-coordinates range from bottom to top
    this_->lastX = xpos;
    this_->lastY = ypos;

    this_->camera.ProcessMouseMovement(xoffset, yoffset);
}

void GameRenderer::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    GameRenderer *this_ = (GameRenderer*)glfwGetWindowUserPointer(window);

    this_->camera.ProcessMouseScroll(yoffset);
}

int GameRenderer::initApp(GLFWwindow*& window, int width, int height){
    /* Init de GLFW */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Création de la fenêtre
    window = glfwCreateWindow(width, height, "AuPetitCraft", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    /* Init de GLEW */
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Initialisation des buffers
    glfwGetFramebufferSize(window, &width, &height); // récupération de la taille des buffers de GLFW
    glViewport(0, 0, width, height);

    // Définition du pointeur utilisateur pour les callbacks
    glfwSetWindowUserPointer(window, this);

    // Défintion de la fonction de gestion des évènements clavier
    glfwSetKeyCallback(window, key_callback);

    // Gestion des évènements souris
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetCursorPosCallback(window, mouse_callback);

    // Gestion des évènements de scroll
    glfwSetScrollCallback(window, scroll_callback);

    // Activation de test de profondeur
    glEnable(GL_DEPTH_TEST);
    // Activation du test de transparence
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return 0;
}