#include <iostream>
#include <fstream>

// .txt - массив данных в формате N и a_i, где i=1..N (ASCII)
// .bin - массив данных в формате N и a_i, где i=1..N (bin)

class DataReader
{
protected:
    std::ifstream m_in;
    std::string m_filename = "default.txt";
    uint32_t* m_data;
    uint8_t m_n;
public:
    DataReader(const std::string& filename) : m_filename(filename)
    {
        
    }

    virtual bool Open() = 0;
    void Close()
    {
        m_in.close();
    }

    virtual void Read() = 0;
    virtual void Write() = 0;

    void GetData(uint32_t* buf, uint32_t& n)
    {
        n = m_n;
        for (int i = 0; i < m_n; i++)
        {
            buf[i] = m_data[i];
        }
    }
};

class TxtReader : public DataReader
{
public:
    TxtReader(const std::string& filename) : DataReader(filename) {}
    virtual ~TxtReader() 
    {
        delete[] m_data;
    }
    bool Open() override
    {
        m_in.open(m_filename);
        if (!m_in.is_open())
        {
            return false;
        }
        return true;
    }

    void Read() override
    {
        m_in >> m_n;
        m_data = new uint32_t[m_n];
        for (int i = 0; i < m_n; i++)
        {
            m_in >> m_data[i];
            //m_in.read((char*)(m_data+i), 1);
        }
    }

    void Write() override
    {

    }
};

class BinReader : public DataReader
{
public:
    BinReader(const std::string& filename) : DataReader(filename) {}
    virtual ~BinReader()
    {
        if(m_data != nullptr)
            delete[] m_data;
    }
    bool Open() override
    {
        m_in.open(m_filename, std::ios::binary);
        if (!m_in.is_open())
        {
            return false;
        }
        return true;
    }

    void Read() override
    {
        int tmp;
        m_in >> tmp;
        m_n = tmp;
        m_data = new uint32_t[m_n];
        for (int i = 0; i < m_n; i++)
        {
            m_in >> m_data[i];
        }
    }

    void Write() override
    {

    }
};

DataReader* Factory(const std::string& filename)
{
    std::string extension = filename.substr(filename.rfind('.') + 1, filename.length()
        - filename.rfind('.') - 1);
    if (extension == "txt")
        return new TxtReader(filename);
    else if (extension == "bin")
        return new BinReader(filename);
    else
        return nullptr;
}

int main()
{
    DataReader* txtReader = new BinReader("input2.bin");

    txtReader->Open();

    uint32_t n;
    uint32_t buf[100];
    txtReader->Read();
    txtReader->GetData(buf, n);

    std::cout << (int)n << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << buf[i] << std::endl;
    }

    delete txtReader;

    /*
    std::ifstream in("input2.bin", std::ios::binary);
    uint8_t n;
    in.read((char*)&n, 1);

    uint8_t* buf = new uint8_t[n];
    in.read((char*)buf, n);

    std::cout << (int)n << std::endl;  

    for (int i = 0; i < n; i++)
    {
        std::cout << (int)buf[i] << std::endl;
    }

    delete[] buf;
    */

    /*
    std::ofstream out("input2.bin", std::ios::binary);
    uint8_t buf[6];
    buf[0] = 5;
    for (int i = 0; i < 5; i++)
    {
        buf[i + 1] = i + 1;
    }
    out.write((char*)buf, 6);
    */
}