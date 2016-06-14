#pragma once
class Notes
{
	std::vector<std::string> notes;


	void AddNotes();
	void ShowNotes();
	void RemoveNotes();
	void ClearNotes();
public:

	void StartNotes();
	Notes(void);
	~Notes(void);
};

