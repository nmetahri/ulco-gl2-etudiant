#include <hv/WebSocketServer.h>

#include <list>
#include <thread>
#include <optional>

class Net {
    private:
        std::list<WebSocketChannelPtr> _channels;

        // pour gérer les noms de client :
        std::list<WebSocketChannelPtr> _pendings;
        std::map<WebSocketChannelPtr, std::string> _connections;

    public:
        Net() = default;
        Net(const Net &) = delete;

        void add(const WebSocketChannelPtr & c) {
            _channels.push_front(c);
            _pendings.push_front(c);
        }

        void del(const WebSocketChannelPtr & c) {
            auto it = std::find(_channels.begin(), _channels.end(), c);
            if (it != _channels.end())
                _channels.erase(it);
        }

        void map(std::function<void(const WebSocketChannelPtr &)> f) {
            for (const WebSocketChannelPtr & c : _channels)
                f(c);
        }

        bool isAvailableName(const std::string& name) {
            for (const auto connection : _connections) {
                if (connection.second == name) {
                    return false;
                }
            }

            return true;
        }

        // pour gérer les noms de client :
        bool giveName(const WebSocketChannelPtr& c, const std::string& n) {
            if (isPending(c) and isAvailableName(n)) {
                _connections.insert({c, n});
                _pendings.remove(c);
                return true;
            }

            return false;
        }

        bool isPending(const WebSocketChannelPtr& c) const{
            for (auto pending: _pendings)
            {
                if (pending == c) return true;
            }
            
            return false;
        }

        std::optional<std::string> findName(const WebSocketChannelPtr& c) const {
            const auto connection = _connections.find(c);
            if (connection != _connections.end()){
                return connection->second;
            }

            return {};
        }
};

