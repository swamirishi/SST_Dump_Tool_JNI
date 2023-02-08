import org.rocksdb.Options;
import org.rocksdb.RocksObject;

public class SSTDumpTool extends RocksObject {

  static {
    System.loadLibrary("sst_file_dump");
  }

  protected SSTDumpTool() {
    super(newSSTDumpTool());
  }

  public void run(String[] args, Options options) {
    this.runInternal(this.getNativeHandle(), args, options.getNativeHandle());
  }

  private native static long newSSTDumpTool();

  private native void runInternal(long nativeHandle, String[] args, long optionsNativeHandle);

  @Override
  protected native void disposeInternal(long handle);

  public static void main(String[] args) {
    new SSTDumpTool().run(new String[]{"--file=/Users/sbalachandran/Documents/code/rdb-read-sst-cpp/000063.sst", "--command=scan"},
            new Options());
  }
}
