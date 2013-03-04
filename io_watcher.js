var swb = require('./socket_watcher');
exports.IOWatcher = typeof swb.SocketWatcher !== 'undefined' ? swb.SocketWatcher : process.binding('io_watcher').IOWatcher;