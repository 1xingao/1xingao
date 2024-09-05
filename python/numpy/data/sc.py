import os
import requests
import threading

def download_image(url, save_path):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            with open(save_path, 'wb') as f:
                f.write(response.content)
            print(f"Downloaded: {save_path}")
        else:
            print(f"Failed to download: {url}")
    except Exception as e:
        print(f"Error occurred while downloading {url}: {e}")

def download_images_from_sogou(keyword, num_images=10):
    base_url = f"https://pic.sogou.com/pics?query={keyword}&mode=1&start=0&reqType=ajax&reqFrom=result&tn=0"

    response = requests.get(base_url)
    if response.status_code != 200:
        print(f"Failed to get image URLs for {keyword}")
        return

    image_urls = response.json().get("items", [])[:num_images]

    if not image_urls:
        print(f"No images found for {keyword}")
        return

    os.makedirs(keyword, exist_ok=True)

    threads = []
    for i, image_url in enumerate(image_urls):
        save_path = os.path.join(keyword, f"{keyword}_{i}.jpg")
        thread = threading.Thread(target=download_image, args=(image_url, save_path))
        thread.start()
        threads.append(thread)

    # Wait for all threads to complete
    for thread in threads:
        thread.join()

    print(f"All images for {keyword} downloaded successfully!")

if __name__ == "__main__":
    keyword_to_search = "cat"  # Change this to the keyword you want to search for
    num_images_to_download = 10  # Change this to the number of images you want to download
    download_images_from_sogou(keyword_to_search, num_images_to_download)