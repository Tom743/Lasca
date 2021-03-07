namespace codes {

struct ExitStatus {
public:
	static const int StatusNoError = 0;
	static const int Success = 0;
	static const int StatusAppInitFailed = 1;
};

struct Colors {
	static const bool Black = 1;
	static const bool White = 0;
};

class CellID
{
public:
	// TODO these should be const
	int x;
	int y;
	CellID(int x, int y) : x(x), y(y)
	{
		if (x%2 != y%2)
		{
			throw "Invalid CellID";	
		}
	}
	CellID& operator=(CellID other)
    {
        std::swap(x, other.x);
        std::swap(y, other.y);
        return *this;
    }
};
}
