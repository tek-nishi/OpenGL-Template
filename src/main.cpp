//
// OpenGL1.1 Tutorial
//

// GLFWのヘッダ内で他のライブラリを取り込む
#define GLFW_INCLUDE_GLEXT
#define GLFW_INCLUDE_GLU

#if defined(_MSC_VER)
// Windows:GLEWをスタティックライブラリ形式で利用
#define GLEW_STATIC
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>


#if defined(_MSC_VER)
// Windows:外部ライブラリのリンク指定
#if defined (_DEBUG)
#pragma comment(lib, "glfw3d.lib")
#pragma comment(lib, "glew32sd.lib")
#else
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#endif
#pragma comment(lib, "OPENGL32.lib")
#pragma comment(lib, "GLU32.lib")
#endif


int main() {
  // 初期化
  if (!glfwInit()) return -1;

  // Window生成
  GLFWwindow* window = glfwCreateWindow(800,
                                        600,
                                        "OpenGL template",
                                        nullptr, nullptr);

  if (!window) {
	  // 生成失敗
	  glfwTerminate();
    return -1;
  }

  // OpenGLをWindowで使えるようにする
  glfwMakeContextCurrent(window);
  // Window画面の更新タイミングをPCディスプレイに同期する
  glfwSwapInterval(1);

#if defined (_MSC_VER)
  // GLEWを初期化(Windows)
  if (glewInit() != GLEW_OK) {
	  // パソコンがOpenGL拡張に対応していなければ終了
	  glfwTerminate();
	  return -1;
  }
#endif

  // これ以降OpenGLの命令が使える

  while (!glfwWindowShouldClose(window)) {
    // フレームバッファをクリア
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //
    // 画面更新処理はここに書く
    //

    // 表示画面と描画画面を入れ替える
    glfwSwapBuffers(window);
    // キー入力などのイベント処理
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
