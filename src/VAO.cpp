#include "../include/VAO.hpp"
#include "../include/VBO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &id);
}

void VAO::linkVBO(VBO vbo, GLuint posLayout, GLuint normalLayout, GLuint texLayout)
{
    vbo.bind();

    // position
    glVertexAttribPointer(posLayout, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)0);
    glEnableVertexAttribArray(posLayout);
    // normal
    glVertexAttribPointer(normalLayout, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)(3 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(normalLayout);
    // texture coordinate
    glVertexAttribPointer(texLayout, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)(6 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(texLayout);

    vbo.unbind();
}
void VAO::linkVBO(VBO vbo, GLuint posLayout, GLuint colorLayout)
{
    vbo.bind();

    // position
    glVertexAttribPointer(posLayout, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void *)0);
    glEnableVertexAttribArray(posLayout);
    // color
    glVertexAttribPointer(colorLayout, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void *)(3 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(colorLayout);

    vbo.unbind();
}

void VAO::linkVBO(VBO vbo, GLuint posLayout, GLuint texLayout, bool texture)
{
    vbo.bind();
    glEnableVertexAttribArray(posLayout);
    glVertexAttribPointer(posLayout, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GL_FLOAT), (void *)0);
    glEnableVertexAttribArray(texLayout);
    glVertexAttribPointer(texLayout, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GL_FLOAT), (void *)(2 * sizeof(float)));
    vbo.unbind();
}

void VAO::bind()
{
    glBindVertexArray(this->id);
}
void VAO::unbind()
{
    glBindVertexArray(0);
}
void VAO::Delete()
{
    glDeleteVertexArrays(1, &id);
}