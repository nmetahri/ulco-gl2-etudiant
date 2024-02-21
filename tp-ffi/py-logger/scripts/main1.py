import Logger

if __name__ == '__main__':

    print('TODO')

    # TODO create a logger and add some items
    log = Logger.Logger()

    log.add_item(Logger.Level.Info, "Info 1")
    log.add_item(Logger.Level.Info, "Info 2")
    log.add_item(Logger.Level.Info, "Info 3")
    log.add_item(Logger.Level.Info, "Info 4")
    log.add_item(Logger.Level.Error, "Error 1")
    log.add_item(Logger.Level.Error, "Error 2")
    log.add_item(Logger.Level.Warning, "Warning 1")
    # TODO report_by_added
    print(log.report_by_added())

    # TODO report_by_level
    print(log.report_by_level())


