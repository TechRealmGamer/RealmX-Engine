#pragma once
class Engine
{
public:
	static Engine* GetInstance()
	{
		if (s_Instance == nullptr)
			s_Instance = new Engine();
		return s_Instance;
	}

	bool Init();

	void Update();
	void Render();
	void Events();

	bool Clean();
	void Quit();

	inline bool IsRunning() { return m_IsRunning; }

private:
	Engine() {}
	static Engine* s_Instance;
	bool m_IsRunning;
};
