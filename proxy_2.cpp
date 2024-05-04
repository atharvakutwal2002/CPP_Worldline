#include <iostream>
using namespace std;

class YouTubeDownloader
{
public:
    virtual void DownloadVideo(const string &videoId) const = 0;
};

class ThirdPartyDownloader : public YouTubeDownloader
{
public:
    void DownloadVideo(const string &videoId) const override
    {
        cout << "ThirdPartyDownloader: Downloading video with ID: " << videoId << endl;
    }
};

class ProxyDownloader : public YouTubeDownloader
{
private:
    ThirdPartyDownloader *third_party_downloader_;

    bool CheckAccess() const
    {

        cout << "ProxyDownloader: Checking access permissions." << endl;
        return true;
    }

    void LogDownload(const string &videoId) const
    {
        cout << "ProxyDownloader: Logging the download of video with ID: " << videoId << endl;
    }

public:
    ProxyDownloader(ThirdPartyDownloader *third_party_downloader)
        : third_party_downloader_(new ThirdPartyDownloader(*third_party_downloader)) {}

    ~ProxyDownloader()
    {
        delete third_party_downloader_;
    }

    void DownloadVideo(const string &videoId) const override
    {
        if (CheckAccess())
        {
            third_party_downloader_->DownloadVideo(videoId);
            LogDownload(videoId);
        }
    }
};

void ClientCode(const YouTubeDownloader &downloader, const string &videoId)
{
    downloader.DownloadVideo(videoId);
}

int main()
{
    cout << "Client: Downloading video using the real downloader:" << endl;
    ThirdPartyDownloader *real_downloader = new ThirdPartyDownloader;
    ClientCode(*real_downloader, "video123");
    cout << endl;

    cout << "Client: Downloading video using the proxy downloader:" << endl;
    ProxyDownloader *proxy_downloader = new ProxyDownloader(real_downloader);
    ClientCode(*proxy_downloader, "video456");

    delete real_downloader;
    delete proxy_downloader;
    return 0;
}
