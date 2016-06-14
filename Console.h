#pragma once
class Console
{
	void Interprete();
	void Execute();
	void ClearConsole();
	void ClearHistory();
public:

	void StartConsole();

	Console(void);
	~Console(void);
};

