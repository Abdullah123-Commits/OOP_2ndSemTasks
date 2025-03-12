#include <iostream>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filePath;
    int size;

public:
    MediaFile(string path, int size) : filePath(path), size(size) {
        cout << "MediaFile constructor called" << endl;
    }

    virtual void play() {
        cout << "Playing media file: " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping media file: " << filePath << endl;
    }

    virtual ~MediaFile() {
        cout << "MediaFile destructor called" << endl;
    }
};

class VisualMedia : virtual public MediaFile {
protected:
    string resolution;

public:
    VisualMedia(string path, int size, string res)
        : MediaFile(path, size), resolution(res) {
        cout << "VisualMedia constructor called" << endl;
    }

    void showResolution() {
        cout << "Resolution: " << resolution << endl;
    }
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(string path, int size, int rate)
        : MediaFile(path, size), sampleRate(rate) {
        cout << "AudioMedia constructor called" << endl;
    }

    void showSampleRate() {
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, int size, string res, int rate)
        : MediaFile(path, size), VisualMedia(path, size, res), AudioMedia(path, size, rate) {
        cout << "VideoFile constructor called" << endl;
    }

    void play() override {
        cout << "Playing video file: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping video file: " << filePath << endl;
    }

    ~VideoFile() {
        cout << "VideoFile destructor called" << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, int size, string res)
        : MediaFile(path, size), VisualMedia(path, size, res) {
        cout << "ImageFile constructor called" << endl;
    }

    void play() override {
        cout << "Displaying image: " << filePath << endl;
    }

    void stop() override {
        cout << "Hiding image: " << filePath << endl;
    }

    ~ImageFile() {
        cout << "ImageFile destructor called" << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, int size, int rate)
        : MediaFile(path, size), AudioMedia(path, size, rate) {
        cout << "AudioFile constructor called" << endl;
    }

    void play() override {
        cout << "Playing audio: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping audio: " << filePath << endl;
    }

    ~AudioFile() {
        cout << "AudioFile destructor called" << endl;
    }
};

int main() {
    MediaFile *media;

    cout << "\nCreating and testing a VideoFile object:\n";
    VideoFile video("video.mp4", 1024, "1920x1080", 44100);
    media = &video;
    media->play();
    media->stop();

    cout << "\nCreating and testing an ImageFile object:\n";
    ImageFile image("image.png", 512, "1024x768");
    media = &image;
    media->play();
    media->stop();

    cout << "\nCreating and testing an AudioFile object:\n";
    AudioFile audio("song.mp3", 256, 44100);
    media = &audio;
    media->play();
    media->stop();

    return 0;
}
