#include "NPrimitiveCircumference.h"
#include "dtPrimitiveVertex.h"
#include "NShaderManagment.h"
#include "NPrimitiveShader.h"
#include "NFramework.h"

#define TwoPI 6.2831853

void NPrimitiveCircumference::Initialize(float x, float y, float radius, int vertexCount) {
	NDrawable2D::Initialize(x, y);

	mRadius = radius;
	mIBO_ID = 0;

	int arraySize = vertexCount + 1;
	float slicedAngle = TwoPI / (float)vertexCount;

	dtPrimitiveVertex* vertexData = new dtPrimitiveVertex[arraySize];
	vertexData[0].SetPosition(x, y);
	vertexData[0].SetColor(255, 255, 255, 255);

	for (int i = 1; i < arraySize; i++)
	{
		float cx = mX + mRadius * cosf(slicedAngle * i);
		float cy = mY + mRadius * sinf(slicedAngle * i);

		vertexData[i].SetPosition(cx, cy);
		vertexData[i].SetColor(255, 255, 255, 255);
	}

	int size = (sizeof(float) * 2 + sizeof(GLubyte) * 4) * arraySize;

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);
	glBufferData(GL_ARRAY_BUFFER, size, &(vertexData[0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Ahora definimos indices
	if (mIBO_ID == 0) {
		glGenBuffers(1, &mIBO_ID);

		int indicesCounter = 0;
		int indicesArraySize = vertexCount * 3; // esto porque cada triangulo tiene 3 vertices
		unsigned int* indicesData = new unsigned int[indicesArraySize];

		for (int i = 0; i < indicesArraySize; i += 3)
		{
			indicesData[i] = 0;
			indicesData[i + 1] = indicesCounter + 1;
			indicesData[i + 2] = indicesCounter + 2;

			indicesCounter++;
		}

		// Manualmente cerrar el ultimo indice
		indicesData[indicesArraySize - 1] = 1;

		mIndicesCount = indicesArraySize;

		int indexDataSize = sizeof(int) * indicesArraySize;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexDataSize, 
			&(indicesData[0]), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	NShaderManagment* shaderManagement = NFramework::GET_FRAMEWORK()->GetShaderManagment();

	const std::string baseShaderPath = "Shaders/PrimitiveShader";
	mCurrentShader = shaderManagement->LoadAndGetShader<NPrimitiveShader>(baseShaderPath);
}

void NPrimitiveCircumference::Draw(float dt) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	mCurrentShader->Use();

	GLuint wvpLocation = mCurrentShader->GetUniformLocation("wvp");
	glm::mat4 cameraMatrix = mRenderCamera->GetResultMatrix();
	glm::mat4 resulMatrix = cameraMatrix * mWorldMatrix;
	// Pasamos la data de la matrix al shader
	glUniformMatrix4fv(wvpLocation, 1, GL_FALSE, &(resulMatrix[0][0]));

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(dtPrimitiveVertex),
		(void*)offsetof(dtPrimitiveVertex, Position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(dtPrimitiveVertex),
		(void*)offsetof(dtPrimitiveVertex, Color));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO_ID);

	// Dibuja en pantalla
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, mIndicesCount, GL_UNSIGNED_INT, (void*)0);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	mCurrentShader->Unuse();
}
