/*******************************************************************************
    Author: Alexey Frolov (alexwin32@mail.ru)

    This software is distributed freely under the terms of the MIT License.
    See "LICENSE" or "http://copyfree.org/content/standard/licenses/mit/license.txt".
*******************************************************************************/

#ifdef WIN32
#include <windows.h>
#include <XGetopt.h>
#else
#include <unistd.h>
#endif
#include <stdint.h>
#include <iostream>
#include <codecvt>
#include <string>
#include <cstdlib>
#include <Cryptor.h>
#include <Exception.h>
#include <File.h>

static void PrintUsage(const std::string &Name)
{
    std::cout << "usage: " + Name + " [-e file] [-d file] [-p file] [-f file] [-n file] [-k file] [-o file] [-i file]" << std::endl;
    std::cout << " -e: encrypt data file" << std::endl;
    std::cout << " -d: decrypt data file" << std::endl;
    std::cout << " -p: public key data file" << std::endl;
    std::cout << " -f: private key data file" << std::endl;
    std::cout << " -n: generate private key into specified data file. Default name is PRIVATE_KEY" << std::endl;
    std::cout << " -k: generate public key into specified data file. Default name is PUBLIC_KEY" << std::endl;
    std::cout << " -o: output file" << std::endl;
    std::cout << " -i: input file" << std::endl;

    exit(0);
}

enum State{
    STATE_UNDEFINED,
    STATE_GEN_PRIVATE_KEY,
    STATE_GEN_PUBLIC_KEY,
    STATE_ENCRYPT,
    STATE_DECRYPT
};

DECLARE_EXCEPTION(ProcessingException);

int32_t main(int32_t argc, TCHAR *argv[])
{
    srand(time(NULL));

    State state = STATE_UNDEFINED;

    std::wstring publicKeyDataFile = L"./PUBLIC_KEY";
    std::wstring privateKeyDataFile = L"./PRIVATE_KEY";

    std::wstring outputFile = L"", inputFile = L"";

    int32_t c;

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    File::Data asf = File::Read(L"text");

    while ((c = getopt(argc, argv, "nkdepi:f:o:h")) != EOF)
        if(c == 'n')
            state = STATE_GEN_PRIVATE_KEY;
        else if(c == 'k')
            state = STATE_GEN_PUBLIC_KEY;
        else if(c == 'e')
            state = STATE_ENCRYPT;
        else if(c == 'd')
            state = STATE_DECRYPT;
        else if(c == 'p')
            publicKeyDataFile = converter.from_bytes(optarg);
        else if(c == 'f')
            publicKeyDataFile = converter.from_bytes(optarg);
        else if(c == 'i')
            inputFile = converter.from_bytes(optarg);
        else if(c == 'o')
            outputFile = converter.from_bytes(optarg);
        else if(c == '?' || c == 'h')
            PrintUsage(argv[0]);

    if(state == STATE_UNDEFINED)
        PrintUsage(argv[0]);

    try{
        if(state == STATE_GEN_PRIVATE_KEY){
        
            std::wstring path = (outputFile.empty()) ? L"./PRIVATE_KEY" : outputFile;

            DummyEncryption::CreatePrivateKey(path);

        }else if(state == STATE_GEN_PUBLIC_KEY){
        
            std::wstring path = (outputFile.empty()) ? L"./PUBLIC_KEY" : outputFile;

            DummyEncryption::CreatePublicKey(path);

        }else if(state == STATE_ENCRYPT){
        
            if(outputFile.empty())
                outputFile = L"./ENCRYPTED";

            if(inputFile.empty())
                throw ProcessingException(L"you must specify input file");

            File::Data fileData = File::Read(inputFile);

            DummyEncryption::EncryptedData output = DummyEncryption::Encrypt(privateKeyDataFile,
                                                                    publicKeyDataFile,
                                                                    {fileData.begin(), fileData.end()});

            const int8_t *dataStartPtr = reinterpret_cast<const int8_t*>(&output[0]);
            const int8_t *dataEndPtr = dataStartPtr + output.size() * sizeof(float);

            File::Rewrite(outputFile, {dataStartPtr, dataEndPtr});

        }else if(state == STATE_DECRYPT){
            
            if(outputFile.empty())
                outputFile = L"./DECRYPTED";

            if(inputFile.empty())
                throw ProcessingException(L"you must specify input file");

            File::Data fileData = File::Read(inputFile);

            size_t encBytesSize = fileData.size() / sizeof(float);

            DummyEncryption::EncryptedData encData(encBytesSize);
            for(size_t i = 0; i < encBytesSize; i++)
                encData[i] = *reinterpret_cast<float*>(&fileData[0 + i * sizeof(float)]);

            DummyEncryption::DecryptedData output = DummyEncryption::Decrypt(privateKeyDataFile,
                                                                    publicKeyDataFile,
                                                                    encData);

            File::Rewrite(outputFile, {output.begin(), output.end()});
        }

    }catch(const Exception &ex){
        std::wcout << L"error:" << ex.What() << std::endl;
        return 1;
    }

    return 0;
}